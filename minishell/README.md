# minishell
42seoul에서 진행하는 minishell프로젝트는 유닉스 셸을 구현하는 프로젝트로, 사용자가 명령어를 입력하고 이를 처리하여 결과를 출력하는 prompt를 만듭니다. <br/>
이 프로젝트는 유닉스 셸의 작동 원리를 이해하고, 시스템 호출, 프로세스 관리, 파이프 라인 관리 및 명령어 실행 원리에 대한 운영체제에 대한 개념을 학습할 수 있습니다.

## 목차
1. [프로젝트 목표](#프로젝트-목표)
2. [주요 기능](#주요-기능)
3. [파일 구조](#파일-구조)
4. [실행 방법](#실행-방법)

## 프로젝트 목표
- **운영 체제 개념 이해**: 프로세스 생성(`fork`) 및 실행(`execve`) 과정 이해 및 부모-자식 프로세스 간의 통신(`pipe`, `wait`) 처리.
- **POSIX 표준 활용**: 시스템 호출을 사용하여 파일 및 프로세스 관리.
- **에러 처리 능력 강화**: 잘못된 명령어, 잘못된 파일 경로, 없는 환경 변수 등 다양한 에러 상황을 처리.
- **builtin 명령어 구현**: 기존 셸 명령어의 동작을 모방하여 직접 구현.
- **문자열 처리**: 환경 변수 해석, single quote, doulbe quote, 경로 처리 및 명령어 파싱.

## 주요 기능
- **프롬프트 제공**: 사용자 입력 대기 및 처리.
- **명령어 실행**: `ls`, `cat` 등 시스템 명령어 실행 지원.
- **환경 변수 처리**: `$PATH`, `$HOME` 등의 환경 변수 해석.
- **내장 명령어 지원**: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- **파이프 처리**: `|`를 사용한 명령어 연결 지원.
- **리다이렉션**: `<`, `>`, `<<`, `>>` 등의 파일 입출력 처리.
- **시그널 처리**: `ctrl c`, `ctrl d`, `ctrl \`에 대한 동작 정의.
- **에러 처리**: 잘못된 입력 및 실행 오류에 대한 명확한 메시지 출력.
- 기본적으로 모든 행동은 [shell reference](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/)를 바탕으로 한다.

## 파일 구조
```
minishell/
├── libft/
├── src/
│   ├── error.c
│   ├── exe_builtin.c
│   ├── heredoc.c
│   ├── init.c
│   ├── ...
│   ├── main.c
│   └── minishell.h
└── Makefile
```

## 실행 방법
### readline
realine을 사용하기 위해서 brew로 readline을 설치해준다.
```bash
brew install readline
```
readline이 설치된 경로를 알기위해 아래 명령어를 실행한다.
```bash
brew info readline
```
아래와 같은 출력문을 통해서 확인할 수 있다.
```
For compilers to find readline you may need to set:
    LDFLAGS="-L/opt/homebrew/opt/readline/lib"
    CPPFLAGS="-I/opt/homebrew/opt/readline/include"
```
위에서 확인한 경로를 Makefile의 LINKING_READLINE_FLAGS와 COMFILE_READLINE_FLAGS에 넣어주자.
1. **프로그램 컴파일**

```bash
make
```
`minishell`이라는 이름의 실행파일이 생성된다.

2. **minishell 실행**
```bash
./minishell
```
을 통해서 아래와 같은 prompt를 확인할 수 있다.
```
minishell$
```

3. **기본 명령어 사용 예시**

- 명령어 실행:
  ```
  minishell$ ls -la
  ```
- 환경 변수 사용:
  ```
  minishell$ echo $HOME
  ```
- 리다이렉션 사용:
  ```
  minishell$ ls > output.txt
  ```
- 파이프 사용:
  ```
  minishell$ cat file.txt | grep keyword
  ```
<img width="1046" alt="image" src="https://github.com/user-attachments/assets/4dd4c6f0-b5cf-4cee-be65-f4f5726a81c9" />

4. **종료**

- 셸 종료:
  ```bash
  exit
  ```  

> **전체 과제에 대한 설명은 [minishell](https://guiltless-break-8cc.notion.site/minishell?pvs=4)를 참고하세요.**
