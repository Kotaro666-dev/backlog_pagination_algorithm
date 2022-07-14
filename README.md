# Get Started

```
$ git clone git@github.com:Kotaro666-dev/backlog_pagination_algorithm.git
$ gcc main.c
$ ./a.out ${current_page} ${last_page}
```

# Example

## Curren page: 3, Last page: 8

```
./a.out 3 8
1 2 3 4 5 6 7 8
```

## Curren page: 3, Last page: 20

```
./a.out 3 20
1 2 3 4 5 6 7 8 9 ...
```

## Curren page: 6, Last page: 20

```
./a.out 6 20
... 2 3 4 5 6 7 8 9 10 ...
```

## Curren page: 9, Last page: 11

```
./a.out 9 11
... 5 6 7 8 9 10 11
```

## Curren page: 9, Last page: 11

```
./a.out 9 11
... 5 6 7 8 9 10 11
```
