#include<string>
#include <cstdio>
#include <utility>
#include <iostream>
//encoding:GBK

using namespace std;

class Student {
protected:
    long num;
    string name;
    char sex;
    int eng;
    int chi;
    int math;
    static int count;
    static double chi_sum;
    static double math_sum;
    static double eng_sum;
public:
    Student(long num, string name, char sex, int eng, int chi, int math);

    Student();

    Student(const Student &s);

    operator double() const;

    friend istream &operator>>(istream &i, Student &s);

    friend ostream &operator<<(ostream &o, const Student &s);

    void show();

    static double avg_eng();

    static double avg_math();

    static double avg_chi();

    int getEng() const;

    int getChi() const;

    int getMath() const;

    virtual double getTotal();
};

int Student::count = 0;
double Student::chi_sum = 0;
double Student::eng_sum = 0;
double Student::math_sum = 0;


Student::Student(long num, string name, char sex, int eng, int chi, int math) : num(num), name(name),
                                                                                sex(sex),
                                                                                eng(eng), chi(chi), math(math) {
    chi_sum += chi;
    math_sum += math;
    eng_sum += eng;
    count++;

}

Student::Student() : num(0), name("noname"), sex('\0'),
                     eng(0), chi(0), math(0) {
    count++;
}

void Student::show() {
    printf("学号：%d\t姓名：%s\t性别：%c\t英语：%d\t语文：%d\t数学：%d\n", this->num, this->name.c_str(), this->sex, this->eng, this->chi,
           this->math);
}

Student::Student(const Student &s) : num(s.num), name(s.name),
                                     sex(s.sex),
                                     eng(s.eng), chi(s.chi), math(s.math) {
    chi_sum += s.chi;
    math_sum += s.math;
    eng_sum += s.eng;
    count++;

}

double Student::avg_eng() {
    return eng_sum / count;
}

double Student::avg_math() {
    return math_sum / count;
}

double Student::avg_chi() {
    return chi_sum / count;
}

Student::operator double() const {
    return this->eng + this->math + this->chi;
}

istream &operator>>(istream &i, Student &s) {
    Student::eng_sum -= s.eng;
    Student::math_sum -= s.math;
    Student::chi_sum -= s.chi;
    i >> s.num >> s.name >> s.sex >> s.eng >> s.chi >> s.math;
    Student::eng_sum += s.eng;
    Student::math_sum += s.math;
    Student::chi_sum += s.chi;
    return i;
}

ostream &operator<<(ostream &o, const Student &s) {
    o << s.num << '\t' << s.name << '\t' << s.sex << '\t' << s.eng << '\t' << s.chi << '\t' << s.math << '\t'
      << (s.chi + s.math + s.eng);
    return o;
}

int Student::getEng() const {
    return eng;
}

int Student::getChi() const {
    return chi;
}

int Student::getMath() const {
    return math;
}

class ScienceStudent : public Student {
protected:
    int phy;
    int chem;
    int bio;
    static double phy_sum;
    static double chem_sum;
    static double bio_sum;
    static int sc_count;
public:
    ScienceStudent();

    operator double() const;

    friend istream &operator>>(istream &i, ScienceStudent &s);

    friend ostream &operator<<(ostream &o, const ScienceStudent &s);

    static double avg_phy();

    static double avg_chem();

    static double avg_bio();

    static void get_average();

    virtual double getTotal();
};


double ScienceStudent::phy_sum = 0;
double ScienceStudent::chem_sum = 0;
double ScienceStudent::bio_sum = 0;
int ScienceStudent::sc_count = 0;

ScienceStudent::ScienceStudent() { ScienceStudent::sc_count++; }

istream &operator>>(istream &i, ScienceStudent &s) {
    ScienceStudent::eng_sum -= s.eng;
    ScienceStudent::math_sum -= s.math;
    ScienceStudent::chi_sum -= s.chi;
    ScienceStudent::phy_sum -= s.phy;
    ScienceStudent::chem_sum -= s.chem;
    ScienceStudent::bio_sum -= s.bio;
    i >> s.num >> s.name >> s.sex >> s.eng >> s.chi >> s.math >> s.phy >> s.chem >> s.bio;
    ScienceStudent::eng_sum += s.eng;
    ScienceStudent::math_sum += s.math;
    ScienceStudent::chi_sum += s.chi;
    ScienceStudent::phy_sum += s.phy;
    ScienceStudent::chem_sum += s.chem;
    ScienceStudent::bio_sum += s.bio;
    return i;
}

ostream &operator<<(ostream &o, const ScienceStudent &s) {
    o << s.num << '\t' << s.name << '\t' << s.sex << '\t' << s.eng << '\t' << s.chi << '\t' << s.math << '\t' << s.phy
      << '\t' << s.chem << '\t' << s.bio << '\t'
      << (s.chi + s.math + s.eng + s.phy + s.chem + s.bio);
    return o;
}

ScienceStudent::operator double() const {
    return this->eng + this->chi + this->math + this->phy + this->chem + this->bio;
}

double ScienceStudent::avg_phy() {
    return ScienceStudent::phy_sum / ScienceStudent::sc_count;
}

double ScienceStudent::avg_chem() {
    return ScienceStudent::chem_sum / ScienceStudent::sc_count;
}

double ScienceStudent::avg_bio() {
    return ScienceStudent::bio_sum / ScienceStudent::sc_count;
}

void ScienceStudent::get_average() {
    printf("The average of physics:%.1f\tchemistry:%.1f\tbiology:%.1f\n",
           ScienceStudent::phy_sum / ScienceStudent::sc_count, ScienceStudent::chem_sum / ScienceStudent::sc_count,
           ScienceStudent::bio_sum / ScienceStudent::sc_count);
}

double ScienceStudent::getTotal() {
    return this->chi+this->math+ this->eng+this->bio+ this->chem+ this->phy;
}


class LiberalArtsStudent : public Student {
protected:
    int his;
    int geo;
    int pol;
    static double his_sum;
    static double geo_sum;
    static double pol_sum;
    static int la_count;
public:
    LiberalArtsStudent();

    operator double() const;

    friend istream &operator>>(istream &i, LiberalArtsStudent &s);

    friend ostream &operator<<(ostream &o, const LiberalArtsStudent &s);

    static double avg_his();

    static double avg_geo();

    static double avg_pol();

    static void get_average();

    virtual double getTotal();
};

double LiberalArtsStudent::his_sum = 0;
double LiberalArtsStudent::geo_sum = 0;
double LiberalArtsStudent::pol_sum = 0;
int LiberalArtsStudent::la_count = 0;

LiberalArtsStudent::LiberalArtsStudent() { LiberalArtsStudent::la_count++; }

istream &operator>>(istream &i, LiberalArtsStudent &s) {
    LiberalArtsStudent::eng_sum -= s.eng;
    LiberalArtsStudent::math_sum -= s.math;
    LiberalArtsStudent::chi_sum -= s.chi;
    LiberalArtsStudent::his_sum -= s.his;
    LiberalArtsStudent::geo_sum -= s.geo;
    LiberalArtsStudent::pol_sum -= s.pol;
    i >> s.num >> s.name >> s.sex >> s.eng >> s.chi >> s.math >> s.his >> s.geo >> s.pol;
    LiberalArtsStudent::eng_sum += s.eng;
    LiberalArtsStudent::math_sum += s.math;
    LiberalArtsStudent::chi_sum += s.chi;
    LiberalArtsStudent::his_sum += s.his;
    LiberalArtsStudent::geo_sum += s.geo;
    LiberalArtsStudent::pol_sum += s.pol;
    return i;
}

LiberalArtsStudent::operator double() const {
    return this->eng + this->chi + this->math + this->his + this->geo + this->pol;
}

ostream &operator<<(ostream &o, const LiberalArtsStudent &s) {
    o << s.num << '\t' << s.name << '\t' << s.sex << '\t' << s.eng << '\t' << s.chi << '\t' << s.math << '\t' << s.his
      << '\t' << s.geo << '\t' << s.pol << '\t'
      << (s.chi + s.math + s.eng + s.his + s.geo + s.pol);
    return o;
}

double LiberalArtsStudent::avg_his() {
    return LiberalArtsStudent::his_sum / LiberalArtsStudent::la_count;
}

double LiberalArtsStudent::avg_geo() {
    return LiberalArtsStudent::geo_sum / LiberalArtsStudent::la_count;
}

double LiberalArtsStudent::avg_pol() {
    return LiberalArtsStudent::pol_sum / LiberalArtsStudent::la_count;
}

void LiberalArtsStudent::get_average() {
    printf("The average of history:%.1f\tgeography:%.1f\tpolitics:%.1f\n",
           LiberalArtsStudent::his_sum / LiberalArtsStudent::la_count,
           LiberalArtsStudent::geo_sum / LiberalArtsStudent::la_count,
           LiberalArtsStudent::pol_sum / LiberalArtsStudent::la_count);
}

double LiberalArtsStudent::getTotal() {
    return this->chi+this->math+ this->eng+this->geo+this->his+this->pol;
}

//int main() {
//    ScienceStudent stu_ss[5];
//    LiberalArtsStudent stu_las[5];
//    int i;
//    cout << "请按以下顺序输入理科生信息：\n学号\t姓名\t性别\t英语\t语文\t数学\t物理\t化学\t生物" << endl;
//    for (i = 0; i < 5; i++)
//        cin >> stu_ss[i];
//    cout << "\n理科生成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t物理\t化学\t生物\t总分\n";
//    for (i = 0; i < 5; i++)
//        cout << stu_ss[i] << endl;
//    cout << "请按以下顺序输入文科生信息：\n学号\t姓名\t性别\t英语\t语文\t数学\t历史\t地理\t政治" << endl;
//    for (i = 0; i < 5; i++)
//        cin >> stu_las[i];
//    cout << "\n文科生成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t历史\t地理\t政治\t总分\n";
//    for (i = 0; i < 5; i++)
//        cout << stu_las[i] << endl;
//    cout << "The average of English:" << Student::avg_eng() << "\tChinese:"
//         << Student::avg_chi() << "\tMath:" << Student::avg_math() << endl;
//    ScienceStudent::get_average();
//    LiberalArtsStudent::get_average();
//    return 0;
//}


bool judge(Student *s1,Student *s2){
    if (s1->getTotal()<s2->getTotal())return true;
    if (s1->getChi()<s2->getChi())return true;
    if (s1->getMath()<s2->getMath())return true;
    if (s1->getEng()<s2->getEng())return true;
    return false;
}


void ToSort(Student **s,int c){
    for (int i = 0; i < c; ++i) {
        for (int j = i; j < c; ++j) {
            if (judge(s[i],s[j])){
                Student *st = s[i];
                s[i]=s[j];
                s[j]=st;
            }
        }
    }
}

int main() {
    Student *stu[10];
    ScienceStudent stu_ss[5];
    LiberalArtsStudent stu_las[5];
    int i;
    int j = 0;
    cout << "请按以下顺序输入理科生信息：\n学号\t姓名\t性别\t英语\t语文\t数学\t物理\t化学\t生物" << endl;
    for (i = 0; i < 5; i++) {
        cin >> stu_ss[i];
        stu[j] = &stu_ss[i];
        j++;
    }
    cout << "\n理科生成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t物理\t化学\t生物\t总分\n";
    for (i = 0; i < 5; i++)
        cout << stu_ss[i] << endl;
    cout << "请按以下顺序输入文科生信息：\n学号\t姓名\t性别\t英语\t语文\t数学\t历史\t地理\t政治" << endl;
    for (i = 0; i < 5; i++) {
        cin >> stu_las[i];
        stu[j] = &stu_las[i];
        j++;
    }
    cout << "\n文科生成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t历史\t地理\t政治\t总分\n";
    for (i = 0; i < 5; i++)
        cout << stu_las[i] << endl;
    ToSort(stu, 10);
    cout << "\n排序后的成绩单：\n学号\t姓名\t性别\t英语\t语文\t数学\t六科总分\n";
    for (i = 0; i < 10; i++)
        cout << *stu[i] << endl;
    cout << "The average of English:" << Student::avg_eng() << "\tChinese:" << Student::avg_chi()
         << "\tMath:“<<Student::getAvgMath()<<endl";
    ScienceStudent::get_average();
    LiberalArtsStudent::get_average();
    return 0;
}