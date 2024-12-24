# Minitalk
42seoul에서 진행하는 MiniTalk 프로젝트는 `client`와 `server` 간의 문자열 통신을 unix signal인 `SIGUSR1`와 `SIGUSR2`를 사용하여 C언어로 구현하는 과제입니다.<br/>
이 프로젝트는 기본적인 프로세스 간 통신(IPC)을 이해하고 unix signal 처리에 대한 학습을 진행합니다.

## 목차
1. [프로젝트 목표](#프로젝트-목표)
2. [파일 구조](#파일-구조)
3. [동작 방식](#동작-방식)
4. [사용 예시](#사용-예시)

## 프로젝트 목표

### 주요 학습 목표
- **유닉스 신호 처리**: `SIGUSR1`과 `SIGUSR2`를 활용하여 데이터 전송.
- **프로세스 간 통신**: `client`와 `server` 간의 signal기반 문자열 전송 구현.
- **문자열 비트 변환**: 문자열을 비트 단위로 전송하고 이를 다시 문자로 변환 처리.

### 구현해야 할 기능
- **server**: `client`부터 받은 signal `SIGUSR1`과 `SIGUSR2`를 통하여 비트 단위로 문자열 생성하여 출력
- **client**: 사용자가 입력한 문자열을 비트단위로 signal `SIGUSR1`과 `SIGUSR2`을 통해 `server`에게 전송

## 파일 구조

```plaintext
minitalk/
├── src/
│   ├── server.c
│   ├── client.c
│   ├── utils.c
│   └── mini_talk.h
└── Makefile
```

## 동작 방식

### 신호를 통한 데이터 전송
1. `client`는 문자열 데이터를 비트 단위로 변환합니다.
2. 각 비트는 `SIGUSR1` 또는 `SIGUSR2`로 변환되어 `server`로 전송됩니다.
   - **`SIGUSR1`**: 비트 1을 나타냅니다.
   - **`SIGUSR2`**: 비트 0을 나타냅니다.
3. `server`는 수신된 signal를 비트로 복호화하고 이를 다시 문자로 변환하여 출력합니다.

### 주요 흐름
1. **`server` 실행**: PID를 출력하고 `client`의 신호를 대기합니다.
2. **`client` 실행**: `server` PID와 메시지를 인자로 받아 `server`에 메시지를 전송합니다.
3. **데이터 처리**: `server`가 signal를 수신하고 이를 처리하여 메시지를 출력합니다.

## 사용 예시

### 컴파일 방법
`Makefile`을 사용하여 `server`와 `client`를 컴파일합니다:
```bash
make
```
- 실행하면 실행파일인 `server`와 `client`이 생성됩니다.
- `make clean`을 사용하면 `make`를 통해 생성된 모든 오브젝트 파일(`*.o`)을 삭제할 수 있습니다.
- `make fclean`은 `make`로 생성된 모든 오브젝트 파일(`*.o`)과 실행파일인 `server`와 `client`를 삭제합니다.
```plaintext
minitalk/
├── src/
│   ├── server.c
│   ├── client.c
│   ├── utils.c
│   ├── server.o
│   ├── client.o
│   ├── utils.o
│   └── mini_talk.h
├── server
├── client
└── Makefile
```

### 실행 방법
1. **`server` 실행**:
   ```bash
   ./server
   ```
   실행하면 `server`의 PID가 출력됩니다. 이 PID를 `client`에서 사용합니다.

2. **`client` 실행**:
   ```bash
   ./client <SERVER_PID> "메시지"
   ```
   - `<SERVER_PID>`: `server` 실행 시 출력된 PID를 입력합니다.
   - `"메시지"`: `server`에 전송할 문자열 메시지.

### 예제
1. `server`를 실행하여 PID를 확인합니다:
   ```bash
   ./server
   server pid 44085
   ```
2. `client`를 PID와 송신할 메세지를 입력하며 실행시킵니다:
   ```bash
   ./client 44085 "hello, world!"
   ```
3. `server`가 수신한 메시지를 출력합니다:
   ```plain text
   hello, world!
   ```

> **전체 과제에 대한 설명은 [miniTalk](https://guiltless-break-8cc.notion.site/miniTalk-70465a34618344bc96ae1bb1496b2929?pvs=4)를 참고하세요.**
