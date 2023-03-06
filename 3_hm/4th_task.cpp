#include <iostream>
#include <string>

int main() {

    int n, m;

    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::cin >> m;
    int b[m];
    for (int j = 0; j < m; j++) {
        std::cin >> b[j];
    }

    int L[n][m];

    int yes = 0;
    for (int j = 0; j < m ; j++ ) {
       if (b[j] == a[0])
        yes = 1;
       L[0][j] = yes;
    }

    yes = 0;
    for (int i = 0; i < n; i++) {
       if(a[i] == b[0]) yes = 1;
       L[i][0] = yes;
    }

    for (int i = 1; i < n; i++) {
       for(int j = 1; j < m ; j++) {
          if(a[i] == b[j])
             L[i][j] = L[i - 1][j - 1] + 1;
          else
             L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
       }
    }
    // Теперь в последнем элементе массива L содержится длина искомой последовательности
    int i = n - 1;
    int j = m - 1;
    int k = n - 1;
    int rez[n];
    while (1) {
          if (L[i - 1][j] == L[i][j] && i != 0)
            {i -= 1; continue;}
          if (L[i][j - 1] == L[i][j] && j != 0)
            {j -= 1; continue;}
          if (j != 0 && i != 0 && L[i - 1][j - 1] == L[i][j])
            {i -= 1; j -= 1; continue;}

          if (L[i][j] != 0)
            {rez[k] = a[i]; k--;}
          else break;

          if (i != 0) {
             i -= 1;
          } else {
                  if (j != 0) {
                        j -= 1;
                  } else break;
                 }
    }


    k++;
    for ( ; k < n; k++) {
        std::cout << rez[k] << " ";
    }


    return 0;
}
