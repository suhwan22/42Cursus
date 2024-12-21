# get_next_line
42seoul에서 진행하는 **get_next_line** 프로젝트는 C 언어를 사용하여, **file descriptor**를 통해 한 번에 한 줄씩 파일을 읽어오는 함수를 구현하는 과제입니다. <br/>
이 프로젝트를 통해서 **file descriptor**를 통한 file I/O, 정적 변수, 메모리 관리, 버퍼 처리에 대한 개념을 학습하고 활용할 수 있습니다.

## 목차
1. [프로젝트 목표](#프로젝트-목표)
2. [파일 구조](#파일-구조)
3. [사용 방법](#사용-방법)

## 프로젝트 목표

### 학습 목표
- **파일 I/O**: `read`함수와 **file descriptor**의 작동 원리를 이해합니다.
- **정적 변수 사용**: 함수 호출 간 상태를 유지하여 데이터를 효율적으로 처리합니다.
- **메모리 관리**: 동적 메모리 할당과 해제를 통해 메모리 누수를 방지합니다.
- **효율적인 버퍼 처리**: 제한된 버퍼 크기로 데이터를 관리하고 성능을 최적화합니다.

### 주요 기능
- 인자로 받은 **file descriptor**에서 **개행 문자**`\n`를 기준으로 한 줄씩 파일 데이터를 분리하여 반환합니다.
- 파일의 끝에 도달하면 `NULL`을 반환합니다.
- 이전 호출 상태를 저장하고 이어서 읽을 수 있도록 정적 변수를 사용합니다.
- 하나의 프로그램에서 여러 개의 **file descriptor**를 사용할 수 있습니다.
- **표준 입력**에서도 동작하도록 구현해야 합니다.

### 함수 프로토타입
```c
char *get_next_line(int fd);
```
- **파라미터**:
  - `fd`: 읽을 **file descriptor**.
- **반환값**:
  - 읽은 한 줄의 문자열 (개행 문자 포함).
  - 파일 끝에 도달하면 `NULL`.

## 파일 구조

프로젝트 디렉토리는 다음과 같은 파일 구조를 가집니다:

```plaintext
get_next_line/
├── src/
│   ├── get_next_line.c
│   ├── get_next_line_utils.c
│   └── get_next_line.h
└── Makefile
```

## 사용 방법

### 1.정적 라이브러리 생성
`Makefile`을 사용하여 정적 라이브러리를 생성합니다.
```bash
make
```
```bash
make BUFFER_SIZE=4242
```
- Makefile 내부의 `BUFFER_SIZE`는 버퍼의 크기를 정의하며, 실행 중 한 번에 읽을 바이트 수를 지정합니다. 설정하지 않은 경우 42입니다.
- 실행하면 `libgnl.a` 파일이 생성됩니다.
- `make clean`을 사용하면 `make`를 통해 생성된 모든 오브젝트 파일(`*.o`)을 삭제할 수 있습니다.
- `make fclean`은 `make`로 생성된 모든 오브젝트 파일(`*.o`)과 `libgnl.a`를 삭제합니다.

### 2. 다른 프로젝트에서 사용
1. 해당 `get_next_line/`를 다른 프로젝트 디렉토리에 복사합니다.
    ```bash
    project/
    │── get_next_line/
    │   ├── src/
    │   ├── Makefile
    │   └── libgnl.a
    └── main.c
    ```
    
2. 필요에 따라 소스 파일에 `get_next_line.h`을 추가합니다:
    ```c
    #include "./get_next_line/src/get_next_line.h"
    #include <fcntl.h>
    #include <stdio.h>

    int main(void) {
      int fd = open("example.txt", O_RDONLY);
      if (fd == -1) {
        perror("Error opening file");
        return 1;
      }

      char *line;
      while ((line = get_next_line(fd)) != NULL) {
        printf("from gnl: %s", line);
        free(line);
      }

      close(fd);
      return 0;
    }
    ```
    위 코드는 파일 `example.txt`에서 한 줄씩 읽어 출력합니다.

3. 컴파일 시 라이브러리를 링크합니다:
    ```bash
    gcc main.c -L./get_next_line -lgnl -o my_program
    ```
    - `-L./get_next_line`: 라이브러리를 get_next_line/ 디렉토리에서 찾습니다.
    - `-lgnl`: `libgnl.a` 파일을 링크합니다.

4. 실행 결과:
    ```
    $ cat example.txt
    hello, world!
    Welcome!!!
    I'm suhwan22
    $ ./my_program
    from gnl: hello, world!
    from gnl: Welcome!!!
    from gnl: I'm suhwan22
    ```

> 해당 함수는 EOF에 도달하기 전에 **file descriptor**가 가리키는 내용이 변경되는 경우와 바이너리 파일에 대해서는 정의 되어있지 않습니다.<br/>
> **전체 과제에 대한 설명은 [get_next_line](https://guiltless-break-8cc.notion.site/gnl-get-next-line-cd1777a22b394322a5eb844e9281491d?pvs=4)를 참고하세요.**
