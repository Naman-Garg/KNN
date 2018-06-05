#include <bits/stdc++.h>
#define key 17
using namespace std;

int main(){
     float a[130][5], d[130];
     char str[125], str1[125];
     float sl = 0.0, sw = 0.0, pl = 0.0, pw = 0.0, sl1 = 0.0, sw1 = 0.0, pl1 = 0.0, pw1 = 0.0, accuracy = 0.0;
     int i = 0, j = 0, k = 0, l = 0, m = 0, it = 0, count = 0, setosa = 0, versicolor = 0, virginica = 0;
     FILE *fp1, *fp2;

     fp1 = freopen("data_training.txt", "r",stdin);
     while(i < 120){
          fscanf(fp1, " %f %f %f %f %s ", &sl, &sw, &pl, &pw, str);
          a[i][0] = sl;
          a[i][1] = sw;
          a[i][2] = pl;
          a[i][3] = pw;
          if(strcmp(str, "setosa") == 0){
               a[i][4] = 0;
          }
          else if(strcmp(str, "versicolor") == 0){
               a[i][4] = 1;
          }
          else if(strcmp(str, "virginica") == 0){
               a[i][4] = 2;
          }
          i++;
     }
     
     fp2 = freopen("test.txt","r", stdin);
     it = 0;
     while(it < 30){
          fscanf(fp2, "%f %f %f %f %s ", &sl1, &sw1, &pl1, &pw1, str1);
          it++;
          setosa = virginica = versicolor = 0;
          
          //calculate the distance
          for (i = 0; i < 120; i++){
               d[i] = sqrt((pow((a[i][0] - sl1), 2)) + (pow((a[i][1] - sw1), 2)) + (pow((a[i][2] - pl1), 2)) + (pow((a[i][3] - pw1), 2)));
          }

          //sort the distance acco. to increasing order
          for (j = 0; j < 120; j++){
               for(k = 0; k < 120-j-1; k++){
                    if(d[k] > d[k+1]){
                         swap(d[k+1], d[k]);
                         swap(a[k+1][0], a[k][0]);
                         swap(a[k+1][1], a[k][1]);
                         swap(a[k+1][2], a[k][2]);
                         swap(a[k+1][3], a[k][3]);
                         swap(a[k+1][4], a[k][4]);
                    }
               }
          }

          //check the frequency of each flower
          for (m = 0; m < key; m++){
               if(a[m][4] == 0)
                    setosa++;
               else if(a[m][4] == 1)
                    versicolor++;
               else if(a[m][4] == 2)
                    virginica++;
          }

          //increment the counter if it match with the flower
          if(setosa >= versicolor && setosa >= virginica){
               cout << "Setosa" << endl;
               if(strcmp(str1, "setosa") == 0)
                    count ++;
          }
          else if (versicolor >= setosa && versicolor >= virginica){
               cout << "versicolor" << endl;
               if(strcmp(str1, "versicolor") == 0)
                    count ++;
          }
          else if(virginica >= setosa && virginica >= versicolor){
               cout << "virginica" << endl;
               if(strcmp(str1, "virginica") == 0)
                    count ++;
          }
     }

     //calculate the accuracy
     accuracy = (count * 100) / 30;
     cout << accuracy << endl;
     fclose(fp1);
     fclose(fp2);
     return 0;
}
