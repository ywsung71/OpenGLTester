# Quick Start Guide

## 빠른 시작 가이드 (Quick Start)

### 1단계: 프로젝트 열기 (Open Project)

```
Visual Studio 2019 이상 실행
→ "Open a project or solution" 선택
→ OpenGLTester.sln 파일 열기
```

### 2단계: 빌드 (Build)

```
상단 메뉴에서 Platform을 "x64"로 선택
→ Ctrl + Shift + B 눌러서 빌드
→ 빌드 성공 메시지 확인
```

### 3단계: 실행 (Run)

```
F5 키 또는 "Local Windows Debugger" 클릭
→ 애플리케이션 창이 나타남
```

### 4단계: PLY 파일 로드 (Load PLY Files)

```
"Load PLY 1" 버튼 클릭
→ sample_cube.ply 선택
→ "Load PLY 2" 버튼 클릭
→ sample_pyramid.ply 선택
```

### 5단계: 3D 모델 조작 (Interact with 3D Models)

#### 회전 (Rotate)
```
OpenGL 창에서 마우스 좌클릭 + 드래그
→ 모델이 회전됩니다
```

#### 줌 (Zoom)
```
OpenGL 창에서 마우스 휠 스크롤
→ 위로: 확대
→ 아래로: 축소
```

#### 투영 모드 변경 (Change Projection)
```
"Orthographic" 라디오 버튼 클릭
→ 직교 투영으로 변경

"Perspective" 라디오 버튼 클릭
→ 원근 투영으로 변경 (기본값)
```

## 5분 튜토리얼 (5-Minute Tutorial)

### 시나리오: 두 개의 3D 모델 비교

**목표**: 큐브와 피라미드를 나란히 로드하고 다양한 각도에서 비교

#### 1분: 프로젝트 빌드 및 실행
1. Visual Studio에서 OpenGLTester.sln 열기
2. Ctrl+Shift+B로 빌드
3. F5로 실행

#### 2분: 첫 번째 모델 로드
1. "Load PLY 1" 클릭
2. sample_cube.ply 선택
3. 큐브가 화면 중앙에 표시됨

#### 3분: 두 번째 모델 로드
1. "Load PLY 2" 클릭
2. sample_pyramid.ply 선택
3. 큐브(왼쪽)와 피라미드(오른쪽)가 나란히 표시됨

#### 4분: 3D 조작 연습
1. 마우스 좌클릭 + 드래그로 회전
2. 마우스 휠로 줌 인/아웃
3. 다양한 각도에서 두 모델 관찰

#### 5분: 투영 모드 비교
1. "Perspective" 선택 (기본값)
   - 자연스러운 원근감 있는 뷰
2. "Orthographic" 선택
   - 원근감 없는 기술 도면 스타일 뷰
3. 두 모드의 차이점 비교

**완료!** 이제 자신의 PLY 파일을 로드해보세요.

## 문제 해결 빠른 참조 (Quick Troubleshooting)

### 빌드 오류: "afxwin.h를 찾을 수 없습니다"
**해결**: Visual Studio Installer → "C++ MFC" 구성 요소 설치

### 실행 오류: "mfc140ud.dll 없음"
**해결**: Visual C++ Redistributable 설치 또는 Release 빌드 사용

### 모델이 표시되지 않음
**해결**: 
- PLY 파일이 ASCII 형식인지 확인
- 파일 경로가 올바른지 확인
- 마우스 휠로 줌 아웃 시도

### 회전이 안됨
**해결**: OpenGL 렌더링 영역 내에서 드래그하는지 확인

## 다음으로 읽어볼 문서 (Next Steps)

궁금한 내용에 따라 적절한 문서를 참조하세요:

| 목적 | 문서 |
|------|------|
| 프로젝트 전체 이해 | README.md |
| 상세한 사용법 | USAGE.md |
| 빌드 상세 가이드 | BUILD.md |
| 코드 구조 이해 | ARCHITECTURE.md |
| UI 디자인 상세 | UI_DESIGN.md |
| 프로젝트 완전 요약 | PROJECT_SUMMARY.md |

## 샘플 PLY 파일 정보

### sample_cube.ply
- **타입**: 컬러 큐브
- **버텍스**: 8개
- **면**: 12개 (삼각형)
- **색상**: 무지개 색상

### sample_pyramid.ply
- **타입**: 컬러 피라미드
- **버텍스**: 5개
- **면**: 6개 (삼각형)
- **색상**: 다양한 색상

## 자신만의 PLY 파일 만들기

간단한 삼각형 PLY 파일 예제:

```ply
ply
format ascii 1.0
element vertex 3
property float x
property float y
property float z
property uchar red
property uchar green
property uchar blue
element face 1
property list uchar int vertex_indices
end_header
0.0 0.0 0.0 255 0 0
1.0 0.0 0.0 0 255 0
0.5 1.0 0.0 0 0 255
3 0 1 2
```

이 파일을 `triangle.ply`로 저장하고 애플리케이션에서 로드해보세요!

## 키보드 단축키 참조 (Keyboard Shortcuts)

### Visual Studio
- `F5`: 디버그 실행
- `Ctrl+F5`: 디버그 없이 실행
- `Ctrl+Shift+B`: 빌드
- `Shift+F5`: 디버그 중지

### 애플리케이션 (현재 버전)
- 마우스 전용 (키보드 단축키는 향후 추가 예정)

## 팁 & 트릭 (Tips & Tricks)

### 💡 Tip 1: 최적의 초기 뷰
모델을 로드한 후 마우스 드래그로 30-45도 각도에서 보면 3D 구조를 가장 잘 파악할 수 있습니다.

### 💡 Tip 2: 모델 비교
두 유사한 모델을 비교할 때는 Orthographic 모드가 크기 차이를 정확히 볼 수 있어 유용합니다.

### 💡 Tip 3: 줌 레벨
모델이 너무 작거나 크게 보이면 마우스 휠로 적절한 크기로 조정하세요.

### 💡 Tip 4: 회전 리셋
회전이 너무 복잡해지면 파일을 다시 로드하면 초기 뷰로 돌아갑니다.

## 자주 묻는 질문 (FAQ)

**Q: 바이너리 PLY 파일을 지원하나요?**  
A: 현재는 ASCII 형식만 지원합니다.

**Q: 텍스처가 있는 모델도 표시되나요?**  
A: 현재는 버텍스 색상만 지원합니다.

**Q: 여러 개의 모델을 로드할 수 있나요?**  
A: 현재는 2개까지 지원합니다.

**Q: 애니메이션을 볼 수 있나요?**  
A: 현재는 정적 모델만 지원합니다.

**Q: OBJ나 STL 파일도 로드할 수 있나요?**  
A: 현재는 PLY 형식만 지원합니다.

## 지원 및 피드백 (Support & Feedback)

문제가 발생하면 다음을 확인하세요:
1. BUILD.md의 "문제 해결" 섹션
2. USAGE.md의 "문제 해결" 섹션
3. PROJECT_SUMMARY.md의 "제한사항" 섹션

---

**축하합니다!** 이제 OpenGL PLY Viewer를 사용할 준비가 되었습니다! 🎉
