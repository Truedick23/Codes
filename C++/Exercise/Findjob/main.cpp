#include "JobCenter.h"
using namespace std;

int main()
{
    JobCenter *jobCenter = new JobCenter();
    University ouc("OUC");

    Student *zhang = new Student("С��", 22, 3.3, jobCenter);
    Experienced *wang = new Experienced("С��", 30, jobCenter);
    Student *li = new Student("С��", 21, 2.4, jobCenter);

    jobCenter -> publishMessage("�ڻԹ�˾��Ҫ10��C++����Ա�� ");
    jobCenter -> notifyJobSeekers();
    cout << endl;

    jobCenter -> publishMessage("������˾��Ҫ8���������ʦ�� ");
    jobCenter -> notifyJobSeekers();
    cout << endl;

    jobCenter -> publishMessage("�ʺ���˾��Ҫ9���繤�� ");
    jobCenter -> notifyJobSeekers();
    cout << endl;

    delete zhang;
    delete wang;
    delete li;
    return 0;
}
