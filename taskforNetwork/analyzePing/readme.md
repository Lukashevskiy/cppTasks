# Анализ времени отклика сайта github.com 

## Сбор статистики по сайту
для начала нам необходимо собрать статистику ping к сайту github.com
(на линуксе я использовал следующую команду)

```
ping -c 1000 github.com > stat.txt
```
## Анализ файла
после нужно просто спарсить вот такую структуру файла и вытащить из него циферки  -)

### структура файла
![Image alt](https://github.com/Lukashevskiy/cppTasks/raw/master/taskforNetwork/analyzePing/file-stats.png)

циферки получены, дальше группируем циферки по повторяемости (группирую с разницей в 10 миллисекунд для наглядности)
и в конце просто подставляем график нормального распределения и видем что-то отдаленно совпадающее.

### итоговый график
![Image alt](https://github.com/Lukashevskiy/cppTasks/raw/master/taskforNetwork/analyzePing/graph.png)
