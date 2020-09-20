
#include <iostream>
#include <fstream>

#include <opencvapp/opencvapp-version.h>
#include <baselib/baselib.h>


namespace baselib {

    void projectInfo() {
        printf("Library template::baselib \n");
        printf("%s, VERSION %s \n", OPENCVAPP_PROJECT_NAME, OPENCVAPP_VERSION);
        printf("========================= \n");
        printf("Name Version %s \n", OPENCVAPP_NAME_VERSION);
        printf("Description %s \n", OPENCVAPP_PROJECT_DESCRIPTION);
        printf("Author: %s \n", OPENCVAPP_AUTHOR_MAINTAINER);
        printf("Domain: %s \n ", OPENCVAPP_AUTHOR_DOMAIN);

        // Library type (static or dynamic)
#ifdef BASELIB_STATIC_DEFINE
        spdlog::info("Library type: STATIC");
#else
        printf("Library type: SHARED \n");
#endif
        printf("Data directory access \n");
        std::cout << "========================================" << std::endl;
        printf("Reading from file \n");
        std::ifstream f("data/DATA_FOLDER.txt");
        if (f.is_open()) {
            std::string line;
            while (getline(f, line)) {
                std::cout << line << '\n';
            }
            f.close();
        } else {
            std::cout << "Unable to open file." << std::endl;
        }
    }

} // namespace baselib