#include <miral/runner.h>
#include <miral/minimal_window_manager.h>
#include <miral/set_window_management_policy.h>
#include <miral/configuration_option.h>
#include <miral/external_client.h>
#include "miral/minimal_window_manager.h"
#include <miral/display_configuration_option.h>
#include <miral/external_client.h>
#include <miral/runner.h>
#include <miral/window_management_options.h>
#include <miral/append_event_filter.h>
#include <miral/internal_client.h>
#include <miral/command_line_option.h>
#include <miral/cursor_theme.h>
#include <miral/decorations.h>
#include <miral/keymap.h>
#include <miral/toolkit_event.h>
#include <miral/x11_support.h>
#include <miral/wayland_extensions.h>
#include <string.h>
#include <miral/append_event_filter.h>
#include <miral/toolkit_event.h>
#include <unistd.h> 
#include <iostream>
#include <miral/configuration_option.h>
#include <miral/external_client.h>


using namespace miral;
using namespace miral::toolkit;

int main(int argc, char const* argv[])
{
    MirRunner runner{argc, argv};
    ExternalClientLauncher launcher;

    auto run_startup_apps = [&](std::vector<std::string> const& apps)
    {
        for(auto const& app : apps)
        {
            int pid = launcher.launch(std::vector<std::string>{app});
        }
    };

    return runner.run_with(
        {
            X11Support{},
            set_window_management_policy<MinimalWindowManager>(),
            display_configuration_options,
            launcher,
            Keymap{},
            ConfigurationOption(run_startup_apps, "component", "Starts the components when the window manager starts; primarily used for starting multiple components, such as shells.")
        });
}