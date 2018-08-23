[CCode(lower_case_cprefix = "alsa_", cheader_filename = "alsa/devices.h")]
namespace Alsa
{
    [Compact]
    [CCode (cprefix = "devices_")]
    public class Devices
    {
        public static GLib.Array<string> list();
    }
}
