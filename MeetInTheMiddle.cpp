#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, C;  
  cin >> n >> C;  // lee número de objetos y capacidad máxima
  vector<int> w(n), v(n);  // vectores de pesos y valores
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> v[i];   // lee cada par (peso, valor)
  }

  int m = n/2, p = (n+1)/2;   // divide en dos mitades
  vector<pair<int, int>> L, R;  // (peso total, valor total)

  // Generar todos los subconjuntos de la mitad izquierda
  for (int s = 0; s < 1<<m; ++s) {
    int W = 0, V = 0;
    for (int i = 0; i < m; ++i) {
      if (s & (1<<i)) {   // si el i-ésimo elemento está incluido
        W += w[i];
        V += v[i];
      }
    }
    L.push_back({W, V});   // guarda (peso, valor)
  }

  // Generar todos los subconjuntos de la mitad derecha
  for (int s = 0; s < 1<<p; ++s) {
    int W = 0, V = 0;
    for (int i = 0; i < p; ++i) {
      if (s & (1<<i)) {
        W += w[m + i];
        V += v[m + i];
      }
    }
    R.push_back({W, V});
  }

  // Ordenar las dos listas por peso
  sort(L.begin(), L.end());
  sort(R.begin(), R.end());

  // Preprocesar R: para cada peso, guardar el máximo valor posible hasta ahí
  int mx = -1e9;
  for (auto& e : R) {
    e.second = max(e.second, mx);
    mx = e.second;
  }

  // Combinar L y R para encontrar la mejor solución
  int ans = -1e9;
  for (int l = 0, r = R.size() - 1; l < L.size(); ++l) {
    // retrocede r hasta que la suma de pesos no exceda la capacidad
    while (r > 0 and R[r].first + L[l].first > C) r -= 1;
    if (R[r].first + L[l].first <= C) {
      ans = max(ans, R[r].second + L[l].second);  // actualiza mejor valor
    }
  }

  cout << ans << endl;  // imprime el valor máximo alcanzable
  return 0;
}
