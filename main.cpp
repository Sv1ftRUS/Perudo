#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
 #include <iomanip>

//#define debug
#define vertPrint
#define NUM_OF_GAMES 10000

using namespace std;

vector <int> player_dice;
vector <int> x_game_result_v;
int x_game_result_v_stat_array[7]={0,0,0,0,0,0,0};
vector <int> game_result_v_stat1;
vector <int> game_result_v_stat2;
vector <int> game_result_v_stat3;
vector <int> game_result_v_stat4;
vector <int> game_result_v_stat5;
vector <int> game_result_v_stat6;

//primary_func_predefinition
void game_init();
void game_modelling();
void game_result();

//secondary_func_predefinition
void x_game_result();
void result_stat_percent (vector<double> &result_v_procent_stat, const vector<int> &result_v_stat);
void result_stat_print (vector<double> &result_v_procent_stat, int num);
void result_stat_print_Vertical (vector<double> &game_result_v_stat1_percent, vector<double> &game_result_v_stat2_percent, vector<double> &game_result_v_stat3_percent, vector<double> &game_result_v_stat4_percent, vector<double> &game_result_v_stat5_percent, vector<double> &game_result_v_stat6_percent);

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "��������� ������������� ���� � ����� - ������." << endl;

    int i=1;
    while(i)
    {
        game_init();
        game_modelling();
        game_result();
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout << "��� ���������� ����� 0, ���� ������ ���������� 1" << endl;
        cin>>i;
        system("cls");
    }
    return 0;
}

void game_init()
{
    int dice_count = 0;
    int player_dice_count =0;

    //������� ��������
    x_game_result_v.clear();
    game_result_v_stat1.clear();
    game_result_v_stat2.clear();
    game_result_v_stat3.clear();
    game_result_v_stat4.clear();
    game_result_v_stat5.clear();
    game_result_v_stat6.clear();


    cout << "����� ���������� ������� � ����:" << endl;
    cin>>dice_count;
    x_game_result_v.resize(dice_count, 0);
    game_result_v_stat1.resize(dice_count, 0);
    game_result_v_stat2.resize(dice_count, 0);
    game_result_v_stat3.resize(dice_count, 0);
    game_result_v_stat4.resize(dice_count, 0);
    game_result_v_stat5.resize(dice_count, 0);
    game_result_v_stat6.resize(dice_count, 0);

    cout << "����� ���������� ����� �������:" << endl;
    cin>>player_dice_count;
    player_dice.resize(player_dice_count, 0);

    cout << "����� �� ������ ����� ������ � ���� ������:" << endl;
    for(int i=0; i<player_dice_count; i++)
    {
        cin>>player_dice[i];
    }
    #ifdef debug
    for (vector<int>::iterator it = player_dice.begin() ; it!=player_dice.end() ; ++it)
                cout<<*it<<" ";
    #endif // debug
}

void x_game_result()
{
    int face_of_cube;
    int player_face_of_cube;
    for(int i=0; i<7; i++)//��������� �������
        x_game_result_v_stat_array[i]=0;

    for (int i = 0; i<player_dice.size(); i++)//��������� � ������ ������ ������
    {
        player_face_of_cube=player_dice.at(i);
        x_game_result_v_stat_array[player_face_of_cube]++;
        #ifdef debug
        cout<<player_face_of_cube<<" ";
        #endif // debug
    }

    for (int i = player_dice.size(); i<game_result_v_stat1.size(); i++)//��������� � ����� ��������� ������
    {

        face_of_cube=1+rand() % 6;
        x_game_result_v_stat_array[face_of_cube]++;
        #ifdef debug
        cout<<face_of_cube<<" ";
        #endif // debug
    }
    #ifdef debug
    cout<<endl;
    cout<<endl;
    cout<<"stat:"<<endl;
    for(int i=0; i<7; i++)
    {
        cout<<x_game_result_v_stat_array[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    #endif // debug
    game_result_v_stat1[x_game_result_v_stat_array[1]]++;
    //game_result_v_stat1[0]=0;
    game_result_v_stat2[x_game_result_v_stat_array[2]]++;
    //game_result_v_stat2[0]=0;
    game_result_v_stat3[x_game_result_v_stat_array[3]]++;
    //game_result_v_stat3[0]=0;
    game_result_v_stat4[x_game_result_v_stat_array[4]]++;
    //game_result_v_stat4[0]=0;
    game_result_v_stat5[x_game_result_v_stat_array[5]]++;
    //game_result_v_stat5[0]=0;
    game_result_v_stat6[x_game_result_v_stat_array[6]]++;
    //game_result_v_stat6[0]=0;
}

void game_modelling()
{

    srand ( time(NULL) );
    cout<<endl;
    for(int i=0; i<NUM_OF_GAMES; i++)//������ ������������� 10000 ���
    {
        x_game_result();
    }
    #ifdef debug
    cout<<"����� ����� ���������� �� 1, ����������� ���� ��� �� ���� ���� ������� 0���, 1���, 2���� � �.�."<<endl;
    for (vector<int>::iterator it_stat = game_result_v_stat1.begin(); it_stat!=game_result_v_stat1.end() ; ++it_stat)
    {
        cout<<*it_stat/100<<"%  ";
    }
    cout<<endl;
    #endif
    #ifdef debug
    #endif // debug
}

void game_result()
{
    cout<<"�����������, ��� �� ���� ���� ������� �� ����� 0���, 1���, 2��� � �.�."<<endl;

    vector<double> game_result_v_stat1_percent(game_result_v_stat1.size(),0);
    result_stat_percent(game_result_v_stat1_percent, game_result_v_stat1);
    #ifndef vertPrint
    result_stat_print (game_result_v_stat1_percent, 1);
    #endif // vertPrint


    vector<double> game_result_v_stat2_percent(game_result_v_stat2.size(),0);
    result_stat_percent(game_result_v_stat2_percent, game_result_v_stat2);
    #ifndef vertPrint
    result_stat_print (game_result_v_stat2_percent, 2);
    #endif // vertPrint

    vector<double> game_result_v_stat3_percent(game_result_v_stat3.size(),0);
    result_stat_percent(game_result_v_stat3_percent, game_result_v_stat3);
    #ifndef vertPrint
    result_stat_print (game_result_v_stat3_percent, 3);
    #endif // vertPrint

    vector<double> game_result_v_stat4_percent(game_result_v_stat4.size(),0);
    result_stat_percent(game_result_v_stat4_percent, game_result_v_stat4);
    #ifndef vertPrint
    result_stat_print (game_result_v_stat4_percent, 4);
    #endif // vertPrint

    vector<double> game_result_v_stat5_percent(game_result_v_stat5.size(),0);
    result_stat_percent(game_result_v_stat5_percent, game_result_v_stat5);
    #ifndef vertPrint
    result_stat_print (game_result_v_stat5_percent, 5);
    #endif // vertPrint

    vector<double> game_result_v_stat6_percent(game_result_v_stat6.size(),0);
    result_stat_percent(game_result_v_stat6_percent, game_result_v_stat6);
    #ifndef vertPrint
    result_stat_print (game_result_v_stat6_percent, 6);
    #endif // vertPrint

    #ifdef vertPrint
    result_stat_print_Vertical (game_result_v_stat1_percent, game_result_v_stat2_percent, game_result_v_stat3_percent, game_result_v_stat4_percent, game_result_v_stat5_percent, game_result_v_stat6_percent);
    #endif // vertPrint
    cout<<endl;
}

void result_stat_percent (vector<double> &result_v_procent_stat, const vector<int> &result_v_stat)//������������ �� ������� � ������� ���� ������ ���� ������� ������, � ������ ������������
{
    result_v_procent_stat.at(0) = NUM_OF_GAMES;
    for(int i=1; i<result_v_procent_stat.size(); i++)
        result_v_procent_stat.at(i) = (result_v_procent_stat.at(i-1) - result_v_stat.at(i-1));//NUM_OF_GAMES)*100;

    for(int i=0; i<result_v_procent_stat.size(); i++)
        result_v_procent_stat.at(i) = (result_v_procent_stat.at(i) * 100) / NUM_OF_GAMES;
}

void result_stat_print (vector<double> &result_v_procent_stat, int num)
{
    cout<<num<<":  ";
    int i=0;
    for (vector<double>::iterator it_stat = result_v_procent_stat.begin(); it_stat!=result_v_procent_stat.end() ; ++it_stat)
    {

        cout<<*it_stat<<"%["<<i<<"���]"<<"\t";
        i++;
    }
    cout<<endl;
    cout<<endl;
}

void result_stat_print_Vertical (vector<double> &game_result_v_stat1_percent, vector<double> &game_result_v_stat2_percent, vector<double> &game_result_v_stat3_percent, vector<double> &game_result_v_stat4_percent, vector<double> &game_result_v_stat5_percent, vector<double> &game_result_v_stat6_percent)
{
    vector<double>::iterator it_stat1 = game_result_v_stat1_percent.begin();
    vector<double>::iterator it_stat2 = game_result_v_stat2_percent.begin();
    vector<double>::iterator it_stat3 = game_result_v_stat3_percent.begin();
    vector<double>::iterator it_stat4 = game_result_v_stat4_percent.begin();
    vector<double>::iterator it_stat5 = game_result_v_stat5_percent.begin();
    vector<double>::iterator it_stat6 = game_result_v_stat6_percent.begin();

    cout.setf(ios::right);
    cout<<setw(5)<<"1"<<setw(11)<<" "<<setw(5)<<"2"<<setw(11)<<" "<<setw(5)<<"3"<<setw(11)<<" "<<setw(5)<<"4"<<setw(11)<<" "<<setw(5)<<"5"<<setw(11)<<" "<<setw(5)<<"6"<<setw(11)<<" "<<endl;
    for (int i=0; i<game_result_v_stat1_percent.size(); i++)
    {
        cout<<fixed<<setprecision(1)<<setw(5)<<*it_stat1<<"%["<<i<<"���]"<<"\t";
        cout<<fixed<<setprecision(1)<<setw(5)<<*it_stat2<<"%["<<i<<"���]"<<"\t";
        cout<<fixed<<setprecision(1)<<setw(5)<<*it_stat3<<"%["<<i<<"���]"<<"\t";
        cout<<fixed<<setprecision(1)<<setw(5)<<*it_stat4<<"%["<<i<<"���]"<<"\t";
        cout<<fixed<<setprecision(1)<<setw(5)<<*it_stat5<<"%["<<i<<"���]"<<"\t";
        cout<<fixed<<setprecision(1)<<setw(5)<<*it_stat6<<"%["<<i<<"���]"<<"\t";
        cout<<endl;

        ++it_stat1;
        ++it_stat2;
        ++it_stat3;
        ++it_stat4;
        ++it_stat5;
        ++it_stat6;
    }
    cout<<endl;
    cout<<endl;
}

