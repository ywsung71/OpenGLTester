# Build Instructions

## 빌드 요구사항 (Build Requirements)

### 필수 소프트웨어 (Required Software)
- **Visual Studio 2019** 이상 (Visual Studio 2019 or later)
- **Windows 10 SDK** (10.0 or later)
- **MFC Libraries** (Visual Studio 설치 시 "C++를 사용한 데스크톱 개발" 워크로드에 포함)

### Visual Studio 워크로드 설치 (Install Visual Studio Workloads)
Visual Studio Installer에서 다음 워크로드를 설치해야 합니다:
1. "C++를 사용한 데스크톱 개발" (Desktop development with C++)
2. 선택적 구성 요소:
   - MSVC v142 - VS 2019 C++ x64/x86 빌드 도구
   - Windows 10 SDK
   - C++ MFC for latest v142 build tools (x86 & x64)

## 빌드 방법 (Build Instructions)

### Visual Studio에서 빌드 (Build in Visual Studio)

1. **프로젝트 열기**
   ```
   Visual Studio에서 OpenGLTester.sln 파일을 엽니다.
   ```

2. **플랫폼 선택**
   - 상단 툴바에서 "x64" 플랫폼 선택
   - Debug 또는 Release 구성 선택

3. **빌드 실행**
   - 메뉴: `빌드` → `솔루션 빌드` (Ctrl+Shift+B)
   - 또는 메뉴: `빌드` → `OpenGLTester 빌드`

4. **실행**
   - 메뉴: `디버그` → `디버깅 시작` (F5)
   - 또는 메뉴: `디버그` → `디버깅하지 않고 시작` (Ctrl+F5)

### 명령줄에서 빌드 (Build from Command Line)

1. **개발자 명령 프롬프트 열기**
   ```
   시작 메뉴 → Visual Studio 2019 → Developer Command Prompt for VS 2019
   ```

2. **프로젝트 디렉토리로 이동**
   ```cmd
   cd path\to\OpenGLTester
   ```

3. **MSBuild로 빌드**
   ```cmd
   msbuild OpenGLTester.sln /p:Configuration=Release /p:Platform=x64
   ```

## 빌드 출력 (Build Output)

빌드가 성공하면 다음 위치에 실행 파일이 생성됩니다:
- Debug 빌드: `x64\Debug\OpenGLTester.exe`
- Release 빌드: `x64\Release\OpenGLTester.exe`

## 문제 해결 (Troubleshooting)

### MFC 라이브러리를 찾을 수 없음
**오류**: "Cannot open include file: 'afxwin.h'"

**해결책**: 
Visual Studio Installer를 실행하고 "C++ MFC for latest v142 build tools" 구성 요소를 설치합니다.

### OpenGL 라이브러리를 찾을 수 없음
**오류**: "Cannot open include file: 'gl/gl.h'"

**해결책**: 
Windows SDK가 올바르게 설치되었는지 확인합니다. OpenGL 헤더는 Windows SDK에 포함되어 있습니다.

### 링크 오류
**오류**: "unresolved external symbol" 관련 오류

**해결책**:
1. 프로젝트 속성 확인:
   - `프로젝트` → `속성` → `링커` → `입력` → `추가 종속성`
   - `opengl32.lib` 및 `glu32.lib`가 포함되어 있는지 확인
2. MFC 사용 설정 확인:
   - `프로젝트` → `속성` → `고급` → `MFC 사용`
   - "공유 DLL에서 MFC 사용"으로 설정

### 런타임 오류
**오류**: "mfc140ud.dll을 찾을 수 없습니다" (Debug 빌드)

**해결책**:
Visual Studio의 재배포 가능 패키지를 설치하거나, Debug 빌드를 개발 환경에서만 실행합니다.

## 개발 환경 설정 (Development Environment Setup)

### 권장 설정 (Recommended Settings)
- **코드 편집기**: Visual Studio Code IntelliSense 활성화
- **디버깅**: F9로 중단점 설정, F5로 디버깅 시작
- **코드 스타일**: Visual Studio 기본 C++ 포맷터 사용

### 유용한 단축키 (Useful Shortcuts)
- `Ctrl+Shift+B`: 솔루션 빌드
- `F5`: 디버깅 시작
- `Ctrl+F5`: 디버깅 없이 실행
- `F7`: 프로젝트 빌드
- `Ctrl+Shift+F7`: 솔루션 다시 빌드

## 추가 정보 (Additional Information)

### 프로젝트 속성 (Project Properties)
- **문자 집합**: Unicode
- **플랫폼 도구 집합**: v143 (Visual Studio 2022) 또는 v142 (Visual Studio 2019)
- **Windows SDK 버전**: 10.0
- **C++ 언어 표준**: C++17

### 종속성 라이브러리 (Dependencies)
이 프로젝트는 다음 라이브러리에 의존합니다:
- **MFC**: Microsoft Foundation Classes
- **OpenGL**: opengl32.lib
- **GLU**: glu32.lib

모든 종속성은 Windows SDK와 Visual Studio에 기본적으로 포함되어 있습니다.
