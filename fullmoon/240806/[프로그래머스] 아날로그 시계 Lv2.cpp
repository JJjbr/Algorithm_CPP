#include <string>
#include <vector>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    double h = (double)(h1 % 12) * 5 + (double)m1 / 12 + (double)s1 / 720;
    double m = (double)m1 + (double)s1 / 60;
    double pre_h = h, pre_m = m;
    while(true) {   
        if(abs(m - h) < 0.000001) {
            answer++;
        }
        else {
            if(abs(h - s1) < 0.000001) {
                answer++;
            }
            if(abs(m - s1) < 0.000001) {
                answer++;
            }
        }
        
        if(h1 > h2) {
            break;
        }
        if(h1 == h2) {
            if(m1 > m2) {
                break;
            }
            if(m1 == m2) {
                if(s1 >= s2) {
                    break;
                }
            }
        }

        s1++;
        if(s1 == 60) {
            s1 = 0;
            m1++;
            if(m1 == 60) {
                m1 = 0;
                h1++;
            }
        }
        m += (double)1 / 60;
        if(abs(m - 60) < 0.000001) {
            m = 0;
        }
        h += (double)1 / 720;
        if(abs(h - 60) < 0.000001) h = 0;
        
        if(s1 == 0) {
            if((59 < m && m < 60) && (59 < pre_m && pre_m < 60)) {
                answer++;
            }
            if((59 < h && h < 60) && (59 < pre_h && pre_h < 60)) {
                answer++;
            }
        }
        else {
            if((s1 - 1 < m && m < s1) && (s1 - 1 < pre_m && pre_m < s1)) {
                answer++;
            }
            if((s1 - 1 < h && h < s1) && (s1 - 1 < pre_h && pre_h < s1)) {
                answer++;
            }
        }
        
        pre_h = h;
        pre_m = m;
    }
    return answer;
}
