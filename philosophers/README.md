# Philosophers
42seoul에서 진행하는 philosophers프로젝트는 고전적인 동시성 문제인 식사하는 철학자 문제를 해결하는 것을 목표로 합니다.<br/>
여러 철학자가 원형 테이블에 앉아 있으며, 각 철학자는 왼쪽과 오른쪽의 포크를 사용해 식사를 해야 합니다.<br/>
이 과정에서 교착 상태(Deadlock)와 데이터 경합(Data race)상태를 방지하는 것이 주요 목표입니다.

## 목차
1. [프로젝트 목표](#프로젝트-목표)
2. [파일 구조](#파일-구조)
3. [실행 예시](#실행-예시)

## 프로젝트 목표
### 학습 목표
- 동기화 메커니즘 이해하고 **뮤텍스(Mutex) 락**을 이용하여 공유 자원 접근을 제어하고 데이터 레이스를 방지한다.
- 멀티스레딩 프로그래밍을 통하여 철학자마다 별도의 스레드를 생성하여 동시성 구현한다.
- 경쟁 상태와 교착 상태 방지하기 위해 올바른 락 전략을 통해 시스템 안정성 확보한다.
- 프로그램 실행 시 발생하는 딜레이를 최대한 효율적으로 설계하여 오차가 실제 시간의 흐름과 거의 비슷하도록 한다.

### 프로그램 구현
- **철학자의 행동** <br/>
  철학자는 아래 3가지 행동을 반복합니다:
   - Eat (식사): 철학자는 양손에 포크를 잡아야만 식사가 가능합니다. 식사 시간 (time_to_eat)이 지나면 포크를 내려놓습니다.
   - Sleep (휴식): 식사 후 포크를 내려놓고 정해진 시간(time_to_sleep) 동안 잠을 잡니다.
   - Think (사고): 철학자는 배고픔을 느끼기 시작하며, 다음 식사를 준비하기 위해 생각에 잠깁니다.

- **테이블 구조 및 포크** <br/>
철학자는 원형 테이블에 앉아 있고, 각 철학자 사이에는 포크가 하나씩 놓여 있습니다.
철학자는 자신의 왼쪽과 오른쪽의 포크를 모두 잡아야만 식사를 시작할 수 있습니다.
포크는 철학자의 수와 동일한 수로 제공됩니다.

- **철학자의 규칙** <br/>
철학자는 절대 동시에 Eat, Sleep, Think를 수행하지 않습니다.
철학자는 굶어 죽지 않도록 식사를 시도하지만, 다른 철학자와 대화하거나 상태를 공유하지 않습니다.
철학자는 죽기 직전이더라도 다른 철학자들에게 이를 알리지 못합니다.

- **테이블 및 철학자 배치** <br/>
철학자는 1번부터 number_of_philosophers번까지 번호를 가집니다.
n번 철학자는 다음과 같은 위치 관계를 가집니다:
왼쪽에 있는 포크: n-1번 철학자
오른쪽에 있는 포크: n+1번 철학자
1번 철학자는 마지막 철학자(number_of_philosophers)와 연결됩니다.

- **프로그램 조건** <br/>
철학자는 개별 스레드로 구현됩니다. 각 스레드는 철학자의 행동을 독립적으로 처리합니다.
뮤텍스(Mutex) 락을 사용하여 포크와 같은 공유 자원에 대한 경쟁 상태를 방지합니다.
특정 철학자가 time_to_die 내에 식사를 하지 못하면 사망하며, 프로그램은 종료됩니다.

- **실행 인자** <br/>
프로그램은 아래 순서의 인자를 받습니다:
  - number_of_philosophers : [필수] 철학자 수
  - time_to_die :  [필수] 철학자가 식사하지 않고 생존할 수 있는 시간(ms)
  - time_to_eat : [필수] 철학자가 식사하는 데 걸리는 시간(ms)
  - time_to_sleep : [필수] 철학자가 잠을 자는 데 걸리는 시간(ms)
  - number_of_times_each_philosopher_must_eat : [선택] 철학자들이 각자 최소 몇 번 식사를 해야 프로그램을 종료할지 지정

## 파일 구조

```
philosophers/
├── src/
│   ├── init.c
│   ├── philo.c
│   ├── philo_utils.c
│   ├── utils.c
│   ├── mutex.c
│   ├── thread_monitor.c
│   ├── thread_philo.c
│   ├── check_valid_arg.c
│   ├── main.c
│   └── philo.h
└── Makefile
```

## 실행 예시

1. **프로그램 컴파일**
```bash
make
```
`philo`라는 이름의 실행파일이 생성됩니다.

2. **프로그램 실행**
```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional: number_of_times_each_philosopher_must_eat]
```

3. **예시**

- 철학자 5명, time_to_die 800ms, time_to_eat 200ms, time_to_sleep 100ms로 실행:
  ```bash
  ./philo 5 800 200 100
  ```
  딜레이가 발생하여 조금씩 오차가 생기더라도 거의 계속 생존할 수 있다.

- 철학자 5명, time_to_die 800ms, time_to_eat 200ms, time_to_sleep 100ms로 실행, number_of_times_each_philosopher_must_eat 7으로 실행:
  ```bash
  ./philo 5 800 200 100 7
  ```
  7번의 식사가 끝나면 자동으로 종료한다.

4. **출력 예시**

```plaintext
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
200 1 is sleeping
200 5 has taken a fork
200 5 has taken a fork
200 5 is eating
200 3 is sleeping
200 2 has taken a fork
200 2 has taken a fork
200 2 is eating
300 1 is thinking
300 3 is thinking
400 5 is sleeping
400 4 has taken a fork
400 4 has taken a fork
400 4 is eating
400 2 is sleeping
400 1 has taken a fork
400 1 has taken a fork
400 1 is eating
500 5 is thinking
500 2 is thinking
600 1 is sleeping
600 4 is sleeping
600 3 has taken a fork
600 3 has taken a fork
600 3 is eating
600 5 has taken a fork
600 5 has taken a fork
600 5 is eating
700 1 is thinking
...
```

> **전체 과제에 대한 설명은 [philosophers](https://guiltless-break-8cc.notion.site/philosophers-a63e9a7d68be42b5b0381521e362fbaf?pvs=4)를 참고하세요.**
