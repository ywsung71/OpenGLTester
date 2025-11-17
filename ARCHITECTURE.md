# OpenGLTester Architecture

## 개요 (Overview)
이 프로젝트는 MFC(Microsoft Foundation Classes)를 기반으로 하는 OpenGL 3D 시각화 애플리케이션입니다.

## 주요 컴포넌트 (Main Components)

### 1. COpenGLTesterApp (OpenGLTester.cpp/h)
- 메인 애플리케이션 클래스
- MFC 애플리케이션 초기화
- 메인 다이얼로그 실행

### 2. COpenGLTesterDlg (OpenGLTesterDlg.cpp/h)
- 메인 다이얼로그 클래스
- UI 이벤트 처리:
  - 버튼 클릭 (PLY 파일 로드)
  - 라디오 버튼 (투영 모드 변경)
  - 마우스 이벤트 (회전, 줌)
- OpenGLRenderer와 상호작용

### 3. OpenGLRenderer (OpenGLRenderer.cpp/h)
- OpenGL 렌더링 엔진
- 주요 기능:
  - OpenGL 컨텍스트 초기화
  - PLY 데이터 렌더링
  - 카메라 컨트롤 (회전, 줌)
  - 투영 모드 전환 (Orthographic/Perspective)
- 두 개의 PLY 모델을 동시에 렌더링 가능

### 4. PLYLoader (PLYLoader.cpp/h)
- PLY 파일 파싱 클래스
- ASCII 형식의 PLY 파일 지원
- 버텍스 데이터 (위치, 색상, 노멀) 로드
- 페이스 데이터 (인덱스) 로드
- 바운딩 박스 계산

## 데이터 흐름 (Data Flow)

```
사용자 입력 (Load PLY 버튼)
    ↓
COpenGLTesterDlg::OnLoadPly1/2()
    ↓
OpenGLRenderer::LoadPLY1/2()
    ↓
PLYLoader::LoadPLY()
    ↓
파일 파싱 및 버텍스/페이스 데이터 저장
    ↓
OpenGLRenderer::CalculateSceneCenter()
    ↓
OpenGLRenderer::Render()
    ↓
화면에 3D 모델 표시
```

## 렌더링 파이프라인 (Rendering Pipeline)

1. **초기화**
   - OpenGL 컨텍스트 생성
   - 조명 및 재질 설정
   - 뷰포트 설정

2. **프레임 렌더링**
   - 프로젝션 행렬 설정 (Orthographic 또는 Perspective)
   - 뷰 행렬 설정 (카메라 위치 및 회전)
   - 모델 렌더링 (삼각형 메시)

3. **사용자 상호작용**
   - 마우스 드래그: 카메라 회전
   - 마우스 휠: 카메라 줌
   - 라디오 버튼: 투영 모드 변경

## UI 레이아웃 (UI Layout)

```
+--------------------------------------------------------+
| [Load PLY 1] [Load PLY 2]  (O) Orthographic  ( ) Perspective |
+--------------------------------------------------------+
|                                                        |
|                                                        |
|              OpenGL Rendering Area                     |
|              (Picture Control)                         |
|                                                        |
|                                                        |
+--------------------------------------------------------+
```

## 투영 모드 (Projection Modes)

### Orthographic (직교 투영)
- 원근감 없는 투영
- 객체 크기가 거리에 따라 변하지 않음
- 기술 도면, CAD에 적합

### Perspective (원근 투영)
- 원근감 있는 투영
- 멀리 있는 객체가 작게 보임
- 자연스러운 3D 시각화

## 카메라 컨트롤 (Camera Controls)

- **회전**: 마우스 왼쪽 버튼 드래그
  - X축 회전: 마우스 Y 방향 이동
  - Y축 회전: 마우스 X 방향 이동
  
- **줌**: 마우스 휠
  - 휠 위로: 줌 인
  - 휠 아래로: 줌 아웃

## 기술 스택 (Tech Stack)

- **Framework**: MFC (Microsoft Foundation Classes)
- **Graphics API**: OpenGL 1.x (Legacy)
- **Build System**: Visual Studio MSBuild
- **Language**: C++17
- **Platform**: Windows
