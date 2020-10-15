#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <limits>
#include <utility> // pair
#include <tuple>
#include <algorithm>

/*

                     0     0     0     0     0           0  0  0  0  0
                                                         __ __
    [1,2,10] means   10    10                           |10 10|__ __ __
                                                            __ __
    [2,3,20] means         20    20                      __|20 20|__ __
                                                            __ __ __ __
    [2,5,25] means         25    25    25    25          __|25 25 25 25|
    ____________________________________________
                     10    55    45    25    25             
*/

class Solution {
public:
    std::vector<int> corpFlightBookings(std::vector<std::vector<int>>& bookings, int n) {
        std::vector<int> output;

        for(int i = 0; i < n; i++) {
            output.push_back(0);
            printf("%d\t", output[i]);
        }
        printf("\n");

        for(int i = 0 ; i < bookings.size(); i++) {
            std::vector<int> sub_book = bookings[i];
            int from  = sub_book[0];
            int to    = sub_book[1];
            int value = sub_book[2];
            printf("from:%d, to:%d, value:%d\n", from, to, value);
            for(int j = from-1; j < to; j++) {
                output[j] += value;
            }
        }
        return output;
    }

    std::vector<int> corpFlightBookings_v2(std::vector<std::vector<int>>& bookings, int n) {
        std::vector<int> output;
        std::vector<int> d_array; // difference array

        for(int i = 0; i < n; i++) {
            output.push_back(0);
            d_array.push_back(0);
            printf("%d\t", output[i]);
        }
        printf("\n");

        for(int i = 0 ; i < bookings.size(); i++) {
            std::vector<int> sub_book = bookings[i];
            int from  = sub_book[0];
            int to    = sub_book[1];
            int value = sub_book[2];
            printf("from:%d, to:%d, value:%d\n", from, to, value);
            /*
              only need to record 2 point (from and to)
                 __ __
                ^     |
              __|     v__
               from   to
            */
            d_array[from-1] += value;   
            d_array[to] -= value; 

            for(int i = 0; i < n; i++) {
                printf("%d\t",d_array[i]);
            }
            printf("\n");
        }
        
        for(int i = 0; i < n; i++) {
            if(i == 0)
                output[i] = d_array[i] + output[i];
            else
                output[i] = d_array[i] + output[i-1];
        }
        return output;
    }
};

int main(int argc, char *argv[]) {
    Solution *s = new Solution();
    std::vector<int> booking1{ 1,2,10 };
    std::vector<int> booking2{ 2,3,20 };
    std::vector<int> booking3{ 2,5,25 };
    std::vector<std::vector<int>> booking;
    booking.push_back(booking1);
    booking.push_back(booking2);
    booking.push_back(booking3);
    std::vector<int> output = s->corpFlightBookings_v2(booking, 5);

    printf("-----------------------------------\n");
    for(int i = 0 ; i < output.size(); i++)
        printf("%d\t", output[i]);
    printf("\n");
}