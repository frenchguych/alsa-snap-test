namespace AlsaSnapTest {

    public class App : Gtk.Application {

        public App() {
            Object(
                application_id: "ch.frenchguy.AlsaSnapTest",
                flags: ApplicationFlags.FLAGS_NONE
            );
        }

        protected override void activate() {
            Alsa.Devices.list();
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
