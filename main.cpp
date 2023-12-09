#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

//#define debug
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

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Программа моделирования игры в кости - Перудо." << endl;
    game_init();
    game_modelling();
    game_result();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    int i;
    cin>>i;
    return 0;
}

void game_init()
{
    int dice_count = 0;
    int player_dice_count =0;
    cout << "Введи количество кубиков в игре." << endl;
    cin>>dice_count;
    x_game_result_v.resize(dice_count, 0);
    game_result_v_stat1.resize(dice_count, 0);
    game_result_v_stat2.resize(dice_count, 0);
    game_result_v_stat3.resize(dice_count, 0);
    game_result_v_stat4.resize(dice_count, 0);
    game_result_v_stat5.resize(dice_count, 0);
    game_result_v_stat6.resize(dice_count, 0);

    cout << "Введи количество своих кубиков" << endl;
    cin>>player_dice_count;
    player_dice.resize(player_dice_count, 0);

    cout << "Введи по одному какие кубики у тебя выпали" << endl;
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
    for(int i=0; i<7; i++)//зануление массива
        x_game_result_v_stat_array[i]=0;

    for (int i = 0; i<player_dice.size(); i++)//вставляем в массив кубики игрока
    {
        player_face_of_cube=player_dice.at(i);
        x_game_result_v_stat_array[player_face_of_cube]++;
        #ifdef debug
        cout<<player_face_of_cube<<" ";
        #endif // debug
    }

    for (int i = player_dice.size(); i<game_result_v_stat1.size(); i++)//вставляем в масси рандомные кубики
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
    for(int i=0; i<NUM_OF_GAMES; i++)//запуск моделирования 10000 игр
    {
        x_game_result();
    }
    #ifdef debug
    cout<<"вывод общей статистики по 1, вероятность того что за одну игру выпадет 0раз, 1раз, 2раза и т.п."<<endl;
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
    cout<<"Веростность, что за одну игру выпадет НЕ МЕНЕЕ 0раз, 1раз, 2раз и т.п."<<endl;

    vector<double> game_result_v_stat1_percent(game_result_v_stat1.size(),0);
    result_stat_percent(game_result_v_stat1_percent, game_result_v_stat1);
    result_stat_print (game_result_v_stat1_percent, 1);

    vector<double> game_result_v_stat2_percent(game_result_v_stat2.size(),0);
    result_stat_percent(game_result_v_stat2_percent, game_result_v_stat2);
    result_stat_print (game_result_v_stat2_percent, 2);

    vector<double> game_result_v_stat3_percent(game_result_v_stat3.size(),0);
    result_stat_percent(game_result_v_stat3_percent, game_result_v_stat3);
    result_stat_print (game_result_v_stat3_percent, 3);

    vector<double> game_result_v_stat4_percent(game_result_v_stat4.size(),0);
    result_stat_percent(game_result_v_stat4_percent, game_result_v_stat4);
    result_stat_print (game_result_v_stat4_percent, 4);

    vector<double> game_result_v_stat5_percent(game_result_v_stat5.size(),0);
    result_stat_percent(game_result_v_stat5_percent, game_result_v_stat5);
    result_stat_print (game_result_v_stat5_percent, 5);

    vector<double> game_result_v_stat6_percent(game_result_v_stat6.size(),0);
    result_stat_percent(game_result_v_stat6_percent, game_result_v_stat6);
    result_stat_print (game_result_v_stat6_percent, 6);
    cout<<endl;
}

void result_stat_percent (vector<double> &result_v_procent_stat, const vector<int> &result_v_stat)//конвертируем из вектора в котором было забито чего сколько выпало, в вектор вероятностей
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

        cout<<*it_stat<<"%["<<i<<"раз]"<<"\t";
        i++;
    }
    cout<<endl;
    cout<<endl;
}
