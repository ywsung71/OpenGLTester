# UI Design Document

## 애플리케이션 창 레이아웃 (Application Window Layout)

### 전체 창 구조 (Overall Window Structure)
```
┌─────────────────────────────────────────────────────────────┐
│ OpenGL PLY Viewer                                      [─][□][×]│
├─────────────────────────────────────────────────────────────┤
│  ┌──────────┐ ┌──────────┐  ◉ Orthographic  ◯ Perspective │
│  │Load PLY 1│ │Load PLY 2│                                  │
│  └──────────┘ └──────────┘                                  │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│                                                             │
│                    OpenGL Rendering Area                    │
│                      (Picture Control)                      │
│                                                             │
│                  • Mouse drag to rotate                     │
│                  • Mouse wheel to zoom                      │
│                                                             │
│                                                             │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

### 컨트롤 상세 (Control Details)

#### 1. Load PLY 1 버튼
- **위치**: 좌측 상단
- **크기**: 60 x 14 DLU
- **기능**: 첫 번째 PLY 파일 로드
- **이벤트**: `OnLoadPly1()`

#### 2. Load PLY 2 버튼
- **위치**: Load PLY 1 버튼 우측
- **크기**: 60 x 14 DLU
- **기능**: 두 번째 PLY 파일 로드
- **이벤트**: `OnLoadPly2()`

#### 3. Orthographic 라디오 버튼
- **위치**: 버튼들 우측
- **크기**: 60 x 10 DLU
- **기능**: 직교 투영 모드 선택
- **이벤트**: `OnRadioOrthographic()`

#### 4. Perspective 라디오 버튼
- **위치**: Orthographic 버튼 우측
- **크기**: 55 x 10 DLU
- **기능**: 원근 투영 모드 선택 (기본값)
- **이벤트**: `OnRadioPerspective()`

#### 5. OpenGL View (Picture Control)
- **ID**: `IDC_OPENGL_VIEW`
- **위치**: 창 중앙 (하단 대부분 차지)
- **크기**: 506 x 363 DLU
- **스타일**: `SS_BLACKFRAME | WS_BORDER`
- **기능**: OpenGL 3D 렌더링 출력

## 렌더링 영역 상세 (Rendering Area Details)

### 단일 모델 렌더링 (Single Model Rendering)
```
┌───────────────────────────────────────────┐
│                                           │
│                                           │
│               ┌─────────┐                │
│               │         │                │
│               │  Model  │                │
│               │    1    │                │
│               │         │                │
│               └─────────┘                │
│                                           │
│                                           │
└───────────────────────────────────────────┘
```

### 두 모델 동시 렌더링 (Dual Model Rendering)
```
┌───────────────────────────────────────────┐
│                                           │
│    ┌─────────┐         ┌─────────┐      │
│    │         │         │         │      │
│    │  Model  │         │  Model  │      │
│    │    1    │         │    2    │      │
│    │         │         │         │      │
│    └─────────┘         └─────────┘      │
│                                           │
│         (좌측 오프셋)      (우측 오프셋)    │
└───────────────────────────────────────────┘
```

## 사용자 인터랙션 플로우 (User Interaction Flow)

### PLY 파일 로드 플로우
```
사용자 클릭           파일 선택           파일 로드           렌더링
"Load PLY 1"    →   대화상자 열림   →   PLY 파싱    →    화면 업데이트
     ↓                   ↓                  ↓                 ↓
  버튼 이벤트        사용자 선택         메모리 적재         OpenGL 드로우
```

### 투영 모드 변경 플로우
```
사용자 선택           라디오 버튼         투영 변경          렌더링
Orthographic    →    상태 업데이트   →  프로젝션 설정  →  화면 업데이트
     ↓                    ↓                  ↓                ↓
  버튼 이벤트         내부 플래그        glOrtho/gluPerspective  재렌더링
```

### 카메라 컨트롤 플로우
```
마우스 입력           델타 계산          카메라 변환         렌더링
드래그/휠        →   이동량 계산    →   회전/줌 적용   →   화면 업데이트
     ↓                    ↓                  ↓                ↓
  마우스 이벤트       좌표 차이          각도/거리 변경      재렌더링
```

## 색상 스킴 (Color Scheme)

### UI 요소
- **배경색**: 표준 대화상자 배경 (밝은 회색)
- **버튼**: 표준 Windows 버튼 스타일
- **라디오 버튼**: 표준 Windows 라디오 버튼

### OpenGL 렌더링
- **배경색**: 어두운 회색 (0.2, 0.2, 0.2)
- **조명**: 
  - 위치: (1.0, 1.0, 1.0)
  - Ambient: (0.3, 0.3, 0.3)
  - Diffuse: (0.7, 0.7, 0.7)
- **모델 색상**: PLY 파일에서 지정된 색상 사용

## 창 크기 및 비율 (Window Size and Proportions)

### 기본 창 크기
- **너비**: 520 DLU (약 780 픽셀 @ 96 DPI)
- **높이**: 400 DLU (약 600 픽셀 @ 96 DPI)
- **최소 크기**: 제한 없음 (리사이징 시 OpenGL 뷰 자동 조정)

### 컨트롤 영역 비율
- **상단 컨트롤 바**: 약 7% (30 DLU)
- **OpenGL 렌더링 영역**: 약 93% (363 DLU)

## 접근성 (Accessibility)

### 키보드 네비게이션
- **Tab**: 다음 컨트롤로 이동
- **Shift+Tab**: 이전 컨트롤로 이동
- **Space**: 버튼 클릭 / 라디오 버튼 선택
- **Enter**: 기본 버튼 실행

### 마우스 컨트롤
- **좌클릭**: 버튼 클릭, 라디오 버튼 선택
- **좌클릭 드래그** (OpenGL 영역): 카메라 회전
- **휠 스크롤** (OpenGL 영역): 카메라 줌

## 다이얼로그 리소스 정의 (Dialog Resource Definition)

### 리소스 스크립트 (Resource Script)
```rc
IDD_OPENGLTESTER_DIALOG DIALOGEX 0, 0, 520, 400
STYLE DS_SETFONT | DS_MODALFRAME | DS_FIXEDSYS | WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU
CAPTION "OpenGL PLY Viewer"
FONT 9, "MS Shell Dlg"
BEGIN
    PUSHBUTTON      "Load PLY 1", IDC_LOAD_PLY1, 7, 7, 60, 14
    PUSHBUTTON      "Load PLY 2", IDC_LOAD_PLY2, 72, 7, 60, 14
    CONTROL         "Orthographic", IDC_RADIO_ORTHOGRAPHIC, "Button", 
                    BS_AUTORADIOBUTTON | WS_GROUP, 140, 8, 60, 10
    CONTROL         "Perspective", IDC_RADIO_PERSPECTIVE, "Button", 
                    BS_AUTORADIOBUTTON, 205, 8, 55, 10
    CONTROL         "", IDC_OPENGL_VIEW, "Static", 
                    SS_BLACKFRAME | WS_BORDER, 7, 30, 506, 363
END
```

## 향후 UI 개선 사항 (Future UI Enhancements)

### 제안 사항
1. **상태 바 추가**: 로드된 파일 이름, 폴리곤 수, FPS 표시
2. **툴바 추가**: 자주 사용하는 기능의 빠른 접근
3. **속성 패널**: 모델 정보 표시 (버텍스 수, 바운딩 박스 등)
4. **카메라 리셋 버튼**: 초기 뷰로 복귀
5. **배경색 선택**: 사용자 정의 배경색
6. **와이어프레임 모드**: 솔리드/와이어프레임 토글
7. **스크린샷 저장**: 현재 뷰를 이미지로 저장

### 개선된 레이아웃 (향후 버전)
```
┌─────────────────────────────────────────────────────────────┐
│ OpenGL PLY Viewer                                      [─][□][×]│
├──────┬──────────────────────────────────────────────────────┤
│ File │ View  │ Tools  │ Help                                │
├──────┴──────────────────────────────────────────────────────┤
│ [📁][📁][📷][⟲][⊞][☰]                                      │
├─────────────────────────────────────────────────────────────┤
│                │                                             │
│   Properties   │          OpenGL Rendering Area             │
│   ┌─────────┐ │                                             │
│   │ Model 1 │ │                                             │
│   │ Info    │ │                                             │
│   └─────────┘ │                                             │
│   ┌─────────┐ │                                             │
│   │ Model 2 │ │                                             │
│   │ Info    │ │                                             │
│   └─────────┘ │                                             │
├────────────────┴─────────────────────────────────────────────┤
│ Model 1: sample_cube.ply (8 vertices, 12 faces) | FPS: 60  │
└─────────────────────────────────────────────────────────────┘
```
