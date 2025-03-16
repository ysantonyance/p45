#include <iostream>
using namespace std;

int main()
{
    /*
    1.	Напишіть програму, яка надає користувачеві можливість ввести з клавіатури кількість гривень і переводить цю кількість у долари,
    євро та біткоїни.
    2.	Напишіть програму, яка переводить кілометри в сухопутні та морські милі.
    3.	Поміняти місцями значення змінних a і b, спочатку за допомогою додаткової третьої змінної, а потім без.
    4.	Ввести з клавіатури два тризначних числа та поміняти у них середні цифри.
    5.	Ввести чотиризначне число і підрахувати суму першої та третьої цифри та різницю між другою та четвертою цифрою.
    6.	Ввести з клавіатури тризначне число та видалити з нього середню цифру.
    7.	Напишіть програму, яка пропонує користувачеві ввести суму грошового вкладу в гривнях, а також процент річних, які виплачує банк.
    Визначити суму грошей, яку виплачуватиме банк вкладникові кожного місяця.
    8.	Напишіть програму, яка переводить фунти в кілограми. Один фунт — 405,9 грама. Потім реалізуйте зворотний переведення —
    з кілограмів у фунти.
    9.	Ввести з клавіатури тризначне число та «перевернути» його.
    10.	Розрахувати загальну масу всіх планет Сонячної системи. Обчислити середнє арифметичне мас планет. Потім — масу кожної планети
    в процентному співвідношенні, якщо взяти за 100% загальну масу всіх планет. У скільки разів маса найбільшої планети більша,
    ніж сума мас усіх інших планет? Усі результати — показати на екрані.
    11.	Ввести довжину, ширину та висоту кімнати. Підрахувати, скільки фарби піде на фарбування стін цієї кімнати, якщо на 1 м²
    стіни припадає N літрів фарби і M% поверхні стін займають вікна та двері. Розрахувати загальну вартість фарби, враховуючи,
    що один літр фарби коштує R гривень.
    */

    //1
    /*
    double uah, dollar = 0.0241416853962518, euro = 0.0221759576250381, bitcoin = 0.0000002922997113;
    cout << "enter the amount of money in uah(grivni): ";
    cin >> uah;

    cout << "in dollars: " << uah * dollar << endl;
    cout << "in euro: " << uah * euro << endl;
    cout << "in bitcoins: " << uah * bitcoin << endl;
    */

    //2
    /*
    double km, land_miles = 1.609, sea_miles = 1.852;
    cout << "enter km: ";
    cin >> km;

    cout << km << "km = " << km / land_miles << " in land miles" << endl;
    cout << km << "km = " << km / sea_miles << " in sea miles" << endl;
    */

    //3
    /*
    //1st option
    int a = 1, b = 5, c;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    c = a; // c = 1, a, b = 5
    a = b; // c = 1, a = 5, b
    b = c; //

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    //2nd option
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    a = b;
    b = 1;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    */

    //4
    /*
    int num1, num2;
    cout << "enter two 3-digit numbers: " << endl;
    cin >> num1 >> num2;

    int digit1_num1 = num1 / 100;
    int digit2_num1 = num1 / 10 % 10;
    int digit3_num1 = num1 % 10;
    int digit1_num2 = num2 / 100;
    int digit2_num2 = num2 / 10 % 10;
    int digit3_num2 = num2 % 10;

    cout << "from " << num1 << " and " << num2 << endl;
    cout << "to " << digit1_num1 << digit2_num2 << digit3_num1
        << " and " << digit1_num2 << digit2_num1 << digit3_num2;
    */
    
    //5
    /*
    int num;
    cout << "enter 4-digit number: ";
    cin >> num;

    int digit1 = num / 1000;
    int digit2 = num / 100 % 10;
    int digit3 = num / 10 % 10;
    int digit4 = num % 10;

    cout << digit1 << " + " << digit3 << " = " << digit1 + digit3 << endl;
    cout << digit2 << " - " << digit4 << " = " << digit2 - digit4 << endl;
    */

    //6
    /*
    int num;
    cout << "enter 3-digit number: ";
    cin >> num;

    int digit1 = num / 100;
    int digit3 = num % 10;

    cout << digit1 << digit3;
    */

    //7
    /*
    //Smonth = P * R/12 * 100
    double P, R;
    //P - сума вкладу
    //R - річна процентна ставка 
    cout << "enter deposit amount(P) and annual percentage rate(R)\n";
    cin >> P >> R;
    double month = (P * R) / (12 * 100);
    cout << month;
    */
    

    //8
    /*
    double kg, lb;
    cout << "enter kg: ";
    cin >> kg;

    cout << kg << "kg = " << kg * 2.205 << "lb" << endl;

    cout << "enter pounds: ";
    cin >> lb;

    cout << lb << "lb = " << lb / 2.205 << "kg" << endl;
    */

    //9
    /*
    int num, e;
    cout << "enter 3-digit number: ";
    cin >> num;

    int digit1 = num / 100;
    int digit2 = num / 10 % 10;
    int digit3 = num % 10;

    e = digit1;
    digit1 = digit3;
    digit3 = e;

    cout << digit1 << digit2 << digit3;
    */

    //10
    /*
    double mercury = 0.32868;
    double venus = 4.81068;
    double earth = 5.97600;
    double mars = 0.63345;
    double jupiter = 1876.64328;
    double saturn = 561.80376;
    double uranus = 86.05440;
    double neptune = 101.59200;

    double all_weight = mercury + venus + earth + mars + jupiter + saturn + uranus + neptune;
    double am = all_weight / 8;

    //double mercury_percent = mercury / all_weight * 100;

    cout << "all planets together are " << all_weight << " of weight\n";
    cout << "their arithmetic mean is equal to " << am << endl << endl;

    cout << "if all planets together would be 100% of weight then\n";
    cout << "mercury = " << mercury / all_weight * 100 << "%\n";
    cout << "venus = " << venus / all_weight * 100 << "%\n";
    cout << "earth = " << earth / all_weight * 100 << "%\n";
    cout << "mars = " << mars / all_weight * 100 << "%\n";
    cout << "jupiter = " << jupiter / all_weight * 100 << "%\n";
    cout << "saturn = " << saturn / all_weight * 100 << "%\n";
    cout << "uranus = " << uranus / all_weight * 100 << "%\n";
    cout << "neptune = " << neptune / all_weight * 100 << "%\n\n";

    cout << "heaviest planet is jupiter, and it's heavier than all the other planets combined by "
        << jupiter - (all_weight - jupiter) << endl;
    */

    //11
    /*
    double lenght, width, height, N, M, R;
    //N - painting per square meter
    //M - % of windows and doors
    //R - the cost of the paint we use
    cout << "enter lenght, width and height of your room in meter\n";
    cin >> lenght >> width >> height;
    cout << "enter how much liters do we use per 1 square meter(N), how many % do windows and doors take in your room(M) and how much does one liter of pain we use cost(R)\n";
    cin >> N >> M >> R;

    double cost = ((2 * (height * width) + 2 * (height * lenght)) * (1 - M / 100) * N) * R;
    //Sкомнаты (2 стены высота*ширина и 2 стены высота*длина)
    //Sкраски (окна и двери в комнате) =  Sкомнаты * (1 - М / 100)
    //Vкраски (необходимое количество краски) = Sкраски * N
    //ну и цена = Vкраски * R

    cout << "we'll have to spend " << cost << " uah(grivni) overall\n";
    */
    
}