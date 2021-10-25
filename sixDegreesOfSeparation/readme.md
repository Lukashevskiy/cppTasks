# Проверка теории 6 рукопожатий

## Получение данных
данные взяты с сайта -
https://snap.stanford.edu/data/index.html

за анализ был взят датасет фейсбука. 
https://snap.stanford.edu/data/ego-Facebook.html


## Преобразование данных для удобства анализа
Поскольку данные представлены в виде списка смежности, но для статистичесего анализа нам будет удобнее использовать матрицу смежности.
для наглядности можно открыть файл output.txt

Далее нам необходимо посчитать колличество всех рукопожатий между всеми людьми.
для это используется алгоритм алгоритм Флойда–Уоршелла он работает за n^3, по этому программа в моем случае работает 10 минут.
код алгоритма

```c++
void alg_Floyd(vector<vector<int> >& d, int n){
    int a =  0;

    for (register int k=0; k<n; ++k){
        if(k % (n/10) == 0){
            cout << a*10 << "%" <<endl;
            a++;
        }
        for (register int i=0; i<n; ++i){

            int bufik = d[i][k];

            for (register int j=0; j<n; ++j){
                int bufkj = d[k][j];

                if (bufik < INF && bufkj < INF)
                    d[i][j] = min (d[i][j], bufik + bufkj);
            }
        }
    }
}
```


## Анализ статистики
Тоесть сколько нужно рукопожатий для того что бы добраться до конкретных людей
у нас есть матрица смежности и мы спокойно можем постоить график 

![Image alt](https://github.com/Lukashevskiy/cppTasks/raw/master/sixDegreesOfSeparation/gpraph.png)

