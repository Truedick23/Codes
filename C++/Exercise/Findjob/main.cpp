#include "JobCenter.h"
using namespace std;

int main()
{
    JobCenter *jobCenter = new JobCenter();
    University ouc("OUC");

    Student *zhang = new Student("小张", 22, 3.3, jobCenter);
    Experienced *wang = new Experienced("小王", 30, jobCenter);
    Student *li = new Student("小李", 21, 2.4, jobCenter);

    jobCenter -> publishMessage("腾辉公司需要10个C++程序员。 ");
    jobCenter -> notifyJobSeekers();
    cout << endl;

    jobCenter -> publishMessage("海景公司需要8个动画设计师。 ");
    jobCenter -> notifyJobSeekers();
    cout << endl;

    jobCenter -> publishMessage("仁海公司需要9个电工。 ");
    jobCenter -> notifyJobSeekers();
    cout << endl;

    delete zhang;
    delete wang;
    delete li;
    return 0;
}
