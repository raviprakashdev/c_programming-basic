int separa (Aresta *v, int p, int r) {
   int c = v[r].peso; // pivô
   int t, j = p;
   int k;
   for ( k = p; /*A*/ k < r; ++k)
      if (v[k].peso <= c) {
         t = v[j].peso, v[j].peso = v[k].peso, v[k].peso = t;
         t = v[j].v, v[j].v = v[k].v, v[k].v = t;
         t = v[j].w, v[j].w = v[k].w, v[k].w = t;
         ++j;
      }
   t = v[j].peso, v[j].peso = v[r].peso, v[r].peso = t;
   t = v[j].v, v[j].v = v[k].v, v[k].v = t;
   t = v[j].w, v[j].w = v[k].w, v[k].w = t;
   return j;
}

void quickSort (Aresta *v, int p, int r)
{
   while (p < r) {
      int j = separa (v, p, r);
      if (j - p < r - j) {
         quickSort (v, p, j-1);
         p = j + 1;
      } else {
         quickSort (v, j+1, r);
         r = j - 1;
      }
   }
}
