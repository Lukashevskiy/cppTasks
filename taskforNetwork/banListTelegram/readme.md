# Задача про маштаб блокировки телеграмма.
в сети существует список заблокированных адресных пространств телеграмма
## Код на питоне(фактически 3 строчки)
```python
with open('blocked-networks.txt', 'r') as f:
        print(sum([2 ** (32 - int(l.split('/')[1].split('\n')[0])) for l in f]))
```
## Ответ - 15832568
(упорство блокировки)