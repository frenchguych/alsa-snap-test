namespace AlsaSnapTest {

    public class App : Gtk.Application {

        public App() {
            Object(
                application_id: "ch.frenchguy.AlsaSnapTest",
                flags: ApplicationFlags.FLAGS_NONE
            );
        }

        protected override void activate() {
            var devices = Alsa.Devices.list();
            for (var i = 0; i < devices.length; i++) {
                var device = devices.index(i);
                stdout.printf("device: %s\n", device);
            }
        }

        public static int main(string[] args) {
            stdout.printf("AlsaSnapTest 0.5 started\n");
            var app = new App();
            var status = app.run(args);
            stdout.printf("AlsaSnapTest 0.5 ended\n");
            return status;
        }
    }
}
