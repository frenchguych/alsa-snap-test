/**
    PiCaster is a podcast recording and streaming application,
    easy to use for beginners, but with enough functionality
    to suit the needs of intermediate or experienced podcasters.
    Copyright (C) 2018  Yannick Mauray
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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

        if (card_num < 0)
        {
            break;
        }

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
            fprintf(stderr, "DEBUG : card_name = %s\n", card_name);
            fprintf(stderr, "DEBUG : card_id = %s\n", card_id);
        }

        snd_ctl_close(card_handle);
    }

    snd_config_update_free_global();

    return list;
}