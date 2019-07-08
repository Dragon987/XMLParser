#include "dxml.h"
#include <stdio.h>



int main()
{

    dxml_t f1 = dxml_parse_file("formula1.xml"), team, driver;
    const char *teamname;

    for (team = dxml_child(f1, "team"); team; team = team->next) {
        teamname = dxml_attr(team, "name");
        for (driver = dxml_child(team, "driver"); driver; driver = driver->next) {
            printf("%s, %s: %s\n", dxml_child(driver, "name")->txt, teamname,
                dxml_child(driver, "points")->txt);
        }
    }
    dxml_free(f1);


}