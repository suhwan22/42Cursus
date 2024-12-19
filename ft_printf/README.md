# ft_printf
42seoul에서 진행하는 **ft_printf** 프로젝트는 C 언어를 사용하여 C 표준 출력 함수 중 하나인 `printf`를 직접 구현하는 과제입니다. <br/>
이 프로젝트를 통해서 'printf'에 대한 이해와 가변 인자에 대한 학습, 활용 및 다양한 출력 형식을 이해할 수 있습니다. <br/>
뿐만 아니라 함수 사용이 제한 되는 42seoul에서 printf처럼 작동하는 ft_printf를 사용할 수 있도록 나만의 정적 라이브러리를 만들 수 있습니다.

## 목차
1. [프로젝트 목표](#프로젝트-목표)
2. [파일 구조](#파일-구조)
3. [사용 방법](#사용-방법)

## 프로젝트 목표

### 학습 목표
- **가변 인자 처리**: `va_list`, `va_start`, `va_arg`, `va_end`를 사용하여 동적 인자 처리를 이해하고 활용합니다.
- **문자열 처리**: 문자열 포맷팅, 숫자 변환, 버퍼 관리에 대한 전문성을 갖춥니다.
- **메모리 관리**: `NULL` 포인터와 같은 경계 조건을 처리하며 메모리 누수가 없도록 합니다.
- **문제 해결 능력**: 모듈화된 효율적이고 오류가 없는 코드를 작성하며 과제 제한 사항을 준수합니다.

### 주요 기능
- 가변 인자 라이브러리(`stdarg.h`)를 사용하여 동적으로 인자를 처리합니다.
- 출력은 표준 출력(`stdout`)으로 보내야 합니다.
- 출력된 문자 수를 반환해야 합니다.
- 원본 `printf` 함수와 최대한 유사한 동작을 구현합니다.

### 지원해야 하는 변환 지시자
- **`%c`**: 단일 문자 출력.
- **`%s`**: 문자열 출력.
- **`%p`**: 메모리 주소(포인터) 출력.
- **`%d` / `%i`**: 부호 있는 10진수 정수 출력.
- **`%u`**: 부호 없는 10진수 정수 출력.
- **`%x` / `%X`**: 16진수 정수 출력 (소문자/대문자).
- **`%%`**: `%` 자체 출력.

## 파일 구조
```bash
ft_printf/
├── src/
│   ├── ft_putnbr_base.c
│   ├── ft_printf.c
│   └── ft_printf.h
└── Makefile
```

## 사용 방법

### 1.정적 라이브러리 생성
`Makefile`을 사용하여 정적 라이브러리를 생성합니다.
```bash
make
```
- 실행하면 `libftprintf.a` 파일이 생성됩니다.
- `make clean`을 사용하면 `make`를 통해 생성된 모든 오브젝트 파일(`*.o`)을 삭제할 수 있습니다.
- `make fclean`은 `make`로 생성된 모든 오브젝트 파일(`*.o`)과 `libftprintf.a`를 삭제합니다.

### 2. 다른 프로젝트에서 사용
1. 해당 `ft_printf/`를 다른 프로젝트 디렉토리에 복사합니다.
    ```bash
    project/
    │── ft_printf/
    │   ├── src/
    │   ├── Makefile
    │   └── libftprintf.a
    └── main.c
    ```
2. 필요에 따라 소스 파일에 `libft.h`을 추가합니다:
    ```c
    #include "./ft_printf/src/ft_printf.h"

    int main()
    {
      ft_printf("Hello, %s!\n", "42Seoul");
      ft_printf("Character: %c\n", 'A');
      ft_printf("Pointer: %p\n", (void *)0xdeadbeef);
      ft_printf("Decimal: %d\n", 12345);
      ft_printf("Hexadecimal: %x\n", 0x1a3f);
      return 0;
    }
    ```

3. 컴파일 시 라이브러리를 링크합니다:
    ```bash
    gcc main.c -I./ft_printf -L./ft_printf -lftprintf -o my_program
    ```
    - `-I./ft_printf`: 헤더 파일을 ft_printf/ 디렉토리에서 찾습니다.
    - `-L./ft_printf`: 라이브러리를 ft_printf/ 디렉토리에서 찾습니다.
    - `-lftprintf`: `libftprintf.a` 파일을 링크합니다.
4. 실행 결과:
    ```
    $ ./my_program
    Hello, 42Seoul!
    Character: A
    Pointer: 0xdeadbeef
    Decimal: 12345
    Hexadecimal: 1a3f
    ```
> **전체 과제에 대한 설명은 [ft_printf](https://www.notion.so/ft_printf-2cf91d91732d4fbd8623fffb91873bc8)를 참고하세요.**
