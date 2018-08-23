#include "devices.h"

#include <alsa/asoundlib.h>

GArray*
devices_list()
{
    int card_num = -1;
    int err;

    GArray* list = g_array_new(FALSE, FALSE, sizeof(gchar*));

    for (;;)
    {
        snd_ctl_t* card_handle;
        if ((err = snd_card_next(&card_num)) < 0)
        {
            fprintf(stderr, "Can't get the next card number : %s\n", snd_strerror(err));
            break;
        }

	    fprintf(stderr, "card_num = %d\n", card_num);
        if (card_num < 0)
        {
            break;
        }

        char* name;
        if ((err = snd_card_get_name(card_num, &name)) < 0)
        {
            fprintf(stderr, "Cannot get card name of card %i : %s\n", card_num, snd_strerror(err));
            continue;
        }
        fprintf(stderr, "card name : %s\n", name);
        free(name);

        if ((err = snd_card_get_longname(card_num, &name)) < 0)
        {
            fprintf(stderr, "Cannot get card long name of card %i : %s\n", card_num, snd_strerror(err));
            continue;
        }
        fprintf(stderr, "card long name : %s\n", name);
        free(name);

        char str[64];
        sprintf(str, "hw:%i", card_num);
        if ((err = snd_ctl_open(&card_handle, str, 0)) < 0)
        {
            fprintf(stderr, "Can't open card %i : %s\n", card_num, snd_strerror(err));
            continue;
        }

        snd_ctl_card_info_t* card_info;
        snd_ctl_card_info_alloca(&card_info);
        if ((err = snd_ctl_card_info(card_handle, card_info)) < 0)
        {
            fprintf(stderr, "Can't get card info for card %i : %s\n", card_num, snd_strerror(err));
        }
        else
        {
            const char* card_name = snd_ctl_card_info_get_name(card_info);
            const char* card_id = snd_ctl_card_info_get_id(card_info);
            gchar* card = g_strdup_printf("%s", card_name);
            g_array_append_val(list, card);
            fprintf(stderr, "card_name = %s\n", card_name);
            fprintf(stderr, "card_id = %s\n", card_id);
        }

        snd_ctl_close(card_handle);
    }

    snd_config_update_free_global();

    return list;
}
