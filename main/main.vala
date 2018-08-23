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

namespace PiCaster {

    public class App : Gtk.Application {

        public App() {
            Object(
                application_id: "ch.frenchguy.PiCaster",
                flags: ApplicationFlags.FLAGS_NONE
            );
        }

        protected override void activate() {
            var main_window = new Gtk.ApplicationWindow(this);
            main_window.title = "PiCaster";

            main_window.set_decorated(false);
            main_window.fullscreen();
            main_window.show_all();

            var devices = Alsa.Devices.list();
            for (var i = 0; i < devices.length; i++) {
                var device = devices.index(i);
                stdout.printf("device: %s\n", device);
            }
        }

        public static int main(string[] args) {
            stdout.printf("PiCaster 0.5 started\n");
            var app = new App();
            var status = app.run(args);
            stdout.printf("PiCaster 0.5 ended\n");
            return status;
        }
    }
}
