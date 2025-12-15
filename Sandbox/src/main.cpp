#include "Kortez/Application.h"
#include "AppLayer.h"

int main() {
    Kortez::ApplicationSpecification appSpec;
    appSpec.Name = "Sandbox";
    appSpec.WindowSpec.Width = 1920;
    appSpec.WindowSpec.Height = 1080;

    Kortez::Application application(appSpec);
    application.PushLayer<AppLayer>();
    application.Run();
}