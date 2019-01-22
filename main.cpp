#include <iostream>
//       0
//      1 2 
//     3 4 5 
//    6 7 8 9
// 10 11 12 13 14 

class Pyr
{
    public:
        Pyr ()
        {
            segment [0] = '|';
            segment [1] = '|';
            segment [2] = '|';
            segment [3] = '|';
            segment [4] = '|';
            segment [5] = '|';
            segment [6] = '|';
            segment [7] = '|';
            segment [8] = '|';
            segment [9] = '|';
            segment [10] = '|';
            segment [11] = '|';
            segment [12] = '|';
            segment [13] = '|';
            segment [14] = '|';
        }

        bool MakeMove (unsigned int start, unsigned int end)
        {
            unsigned char stick = start;

                // check if valid
                while (stick <= end)
                {
                    if (segment [stick] != '|') return false;
                    stick++;
                }

                // if I reach this point the move is valid
                while (start <= end)
                {
                    segment [start] = '+';
                    start++;
                }

                return true;
        }

        bool AreMovesAvailable (void)
        {
            for (unsigned int i; i < size; ++i)
            {
                if (segment [i] == '|') return true;
            }

            return false;
        }

        void Dislpay (void) 
        {
            std::cout 
                << " " 
                << " " 
                << " " 
                << " " 
                << " " << segment [0]
                << std::endl;
            std::cout 
                << " " 
                << " " 
                << " " 
                << " " << segment [1]
                << " " << segment [2]
                << std::endl;
            std::cout 
                << " " 
                << " " 
                << " " << segment [3]
                << " " << segment [4]
                << " " << segment [5]
                << std::endl;
            std::cout 
                << " " 
                << " " << segment [6]
                << " " << segment [7]
                << " " << segment [8]
                << " " << segment [9]
                << std::endl;
            std::cout 
                << " " << segment [10]
                << " " << segment [11]
                << " " << segment [12]
                << " " << segment [13]
                << " " << segment [14]
                << std::endl;
        };
        static const int size = 15;

    private:
        char segment [size];

};

int main (void)
{
    unsigned int start;
    unsigned int end;

    Pyr p;
    do
    {
        p.Dislpay ();
        std::cout << "Please enter a move (two space separated number between 0 and " 
            << p.size - 1 << " e.g. 6 9" << std::endl;
        std::cin >> start >> end;
        p.MakeMove (start, end);
        p.Dislpay ();

        //check victory
    }
    while (p.AreMovesAvailable ());

    return 0;
}
