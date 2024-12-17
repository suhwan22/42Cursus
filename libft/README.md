# libft
42seoul에서 진행하는 **libft** 프로젝트는 C 언어를 사용하여 표준 라이브러리의 일부를 직접 구현하는 과제입니다.<br/>
이 프로젝트를 통해 C 언어의 기본 개념을 깊이 있게 이해하고, 나만의 정적 라이브러리를 만들 수 있습니다.


## 목차
1. [프로젝트 목표](#프로젝트-목표)
2. [파일 구조](#파일-구조)
3. [사용 방법](#사용-방법)
4. [구현된 함수 목록](#구현된-함수-목록)


## 프로젝트 목표
- C 언어의 표준 라이브러리 함수를 이해하고 직접 구현합니다.
- 정적 라이브러리 `libft.a`를 만들어 다른 프로젝트에서 사용할 수 있도록 합니다.
- 포인터, 메모리, 문자열 조작 등의 C 언어 핵심 개념을 학습합니다.
- [42Norminette](https://github.com/taeng42/norminette/blob/master/pdf/ko.norm.pdf) 스타일 가이드에 맞춘 코드를 작성합니다.


## 파일 구조
```bash
libft/
├── src/
│    ├── ft_atoi.c
│    ├── ft_bzero.c
│    ├── ft_calloc.c
│    ├── ft_isalnum.c
│    ├── ft_isalpha.c
│    ├── ft_isascii.c
│    ├── ft_isdigit.c
│    ├── ft_isprint.c
│    ├── ft_itoa.c
│    ├── ...
│    ├── ...
│    └── libft.h
└── Makefile
```

## 사용 방법

### 1. 정적 라이브러리 생성
`Makefile`을 사용하여 정적 라이브러리를 생성합니다.
```bash
make
```
- 실행하면 `libft.a` 파일이 생성됩니다.
- `make clean`을 사용하면 `make`를 통해 생성된 모든 오브젝트 파일(`*.o`)을 삭제할 수 있습니다.
- `make fclean`은 `make`로 생성된 모든 오브젝트 파일(`*.o`)과 `libft.a`를 삭제합니다.

### 2. 다른 프로젝트에서 사용
1. 해당 `libft/`를 다른 프로젝트 디렉토리에 복사합니다.
    ```bash
    project/
    │── libft/
    └── main.c
    ```
2. 필요에 따라 소스 파일에 `libft.h`을 추가합니다:
    ```c
    #include <stdio.h>
    #include "./libft/src/libft.h"

    int main()
    {
	    char str[10] = "hello";
	    printf("str len: %d\n", ft_strlen(str));
        return 0;
    }
    ```
4. 컴파일 시 라이브러리를 링크합니다:
    ```bash
    gcc main.c -I./libft -L./libft -lft -o my_program
    ```
    - `-I./libft`: 헤더 파일을 libft/ 디렉토리에서 찾습니다.
    - `-L./libft`: 라이브러리를 libft/ 디렉토리에서 찾습니다.
    - `-lft`: `libft.a` 파일을 링크합니다.
5. 실행 결과:
   ```bash
   $ ./my_program
   str len: 5
    ```

## 구현된 함수 목록

### 문자열 함수
- `ft_strlen` : 문자열의 길이를 반환합니다.
- `ft_strcpy` : 문자열을 복사합니다.
- `ft_strdup` : 문자열을 복제합니다.
- `ft_strncmp` : 두 문자열을 비교합니다.

### 메모리 함수
- `ft_memset` : 메모리를 특정 값으로 초기화합니다.
- `ft_memcpy` : 메모리 블록을 복사합니다.
- `ft_memmove` : 결침을 가리는 메모리 블록을 복사합니다.

### 변환 함수
- `ft_atoi` : 문자열을 정수로 변환합니다.

### 연결 리스트 함수
- `ft_lstnew` : 새로운 연결 리스트 노드를 생성합니다.
- `ft_lstadd_front` : 연결 리스트의 앞에 노드를 추가합니다.
- `ft_lstsize` : 연결 리스트의 크기를 반환합니다.

> **전체 함수에 대한 설명은 [libft](https://guiltless-break-8cc.notion.site/libft-21e73be3d2574cb79db3fc071186bee1?pvs=4)를 참고하세요.**
