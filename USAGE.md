# 사용 가이드 (Usage Guide)

## 애플리케이션 시작 (Starting the Application)

1. OpenGLTester.exe를 실행합니다.
2. 메인 다이얼로그 창이 나타납니다.

## UI 구성 (UI Components)

### 상단 컨트롤 바 (Top Control Bar)
```
[Load PLY 1] [Load PLY 2]  (•) Orthographic  ( ) Perspective
```

- **Load PLY 1 버튼**: 첫 번째 PLY 파일 로드
- **Load PLY 2 버튼**: 두 번째 PLY 파일 로드
- **Orthographic 라디오 버튼**: 직교 투영 모드
- **Perspective 라디오 버튼**: 원근 투영 모드 (기본값)

### OpenGL 뷰어 영역 (OpenGL Viewer Area)
- 중앙의 큰 영역은 3D 모델을 표시하는 OpenGL 렌더링 창입니다.
- 이 영역에서 마우스로 카메라를 조작할 수 있습니다.

## 기본 사용법 (Basic Usage)

### 1. PLY 파일 로드하기 (Loading PLY Files)

#### 첫 번째 모델 로드
1. **"Load PLY 1"** 버튼 클릭
2. 파일 선택 대화상자에서 PLY 파일 선택
3. "열기" 버튼 클릭
4. 모델이 화면 왼쪽에 표시됩니다 (두 모델 로드 시)

#### 두 번째 모델 로드
1. **"Load PLY 2"** 버튼 클릭
2. 파일 선택 대화상자에서 PLY 파일 선택
3. "열기" 버튼 클릭
4. 모델이 화면 오른쪽에 표시됩니다

#### 단일 모델 보기
- 하나의 모델만 로드하면 화면 중앙에 표시됩니다.

#### 두 모델 동시 보기
- 두 모델을 모두 로드하면 나란히 표시되어 비교가 가능합니다.

### 2. 카메라 조작 (Camera Controls)

#### 회전 (Rotation)
- **마우스 왼쪽 버튼을 누른 채 드래그**
- 좌우 드래그: Y축 중심으로 회전
- 상하 드래그: X축 중심으로 회전
- 모델을 다양한 각도에서 볼 수 있습니다

#### 줌 인/아웃 (Zoom In/Out)
- **마우스 휠 위로**: 줌 인 (확대)
- **마우스 휠 아래로**: 줌 아웃 (축소)
- 모델에 가까이 다가가거나 멀리서 볼 수 있습니다

### 3. 투영 모드 변경 (Changing Projection Mode)

#### Perspective (원근 투영) - 기본 모드
- **Perspective 라디오 버튼 선택**
- 멀리 있는 객체가 작게 보이는 자연스러운 3D 뷰
- 게임이나 일반적인 3D 시각화에 적합

#### Orthographic (직교 투영)
- **Orthographic 라디오 버튼 선택**
- 원근감 없이 모든 객체가 같은 크기로 보임
- CAD, 기술 도면, 정밀 측정에 적합

## 고급 기능 (Advanced Features)

### 다중 모델 비교 (Comparing Multiple Models)
1. PLY 1과 PLY 2를 각각 로드
2. 두 모델이 나란히 표시됩니다
3. 동일한 카메라 각도에서 두 모델을 비교할 수 있습니다

### 컬러 렌더링 (Color Rendering)
- PLY 파일에 색상 정보가 포함된 경우 자동으로 표시됩니다
- 조명 효과가 적용되어 3D 깊이감을 제공합니다

## 샘플 파일 사용 (Using Sample Files)

프로젝트에는 두 개의 샘플 PLY 파일이 포함되어 있습니다:

### sample_cube.ply
- 컬러 큐브 모델
- 8개의 꼭지점과 12개의 면
- 각 면마다 다른 색상

### sample_pyramid.ply
- 컬러 피라미드 모델
- 5개의 꼭지점과 6개의 면
- 다양한 색상의 삼각형 면

### 샘플 파일 로드 방법
1. "Load PLY 1" 클릭
2. 프로젝트 폴더에서 `sample_cube.ply` 선택
3. "Load PLY 2" 클릭
4. 프로젝트 폴더에서 `sample_pyramid.ply` 선택
5. 두 모델이 나란히 표시됩니다

## 팁 & 요령 (Tips & Tricks)

### 최적의 시각화를 위한 팁
1. **초기 뷰 설정**: 모델 로드 후 마우스 드래그로 최적의 각도 찾기
2. **줌 레벨 조정**: 마우스 휠로 모델 전체가 보이도록 조정
3. **투영 모드 비교**: 두 투영 모드를 전환하며 차이점 확인

### 모델 비교 워크플로우
1. 두 개의 유사한 모델 로드
2. Perspective 모드에서 전체적인 형태 비교
3. Orthographic 모드로 전환하여 정확한 크기와 비율 비교
4. 마우스 드래그로 다양한 각도에서 차이점 확인

### 성능 최적화
- 매우 큰 PLY 파일은 로딩 및 렌더링에 시간이 걸릴 수 있습니다
- 원활한 회전을 위해 적당한 크기의 모델 사용 권장

## 지원되는 PLY 파일 형식 (Supported PLY File Format)

### 파일 형식 요구사항
- **형식**: ASCII PLY (텍스트 형식)
- **버전**: PLY 1.0
- **필수 요소**:
  - vertex 요소 (x, y, z 좌표)
  - face 요소 (vertex_indices 리스트)

### 선택적 속성 (Optional Properties)
- **색상**: red, green, blue (0-255 범위)
- **법선**: nx, ny, nz (조명 계산용)

### PLY 파일 예제
```
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
0.0 1.0 0.0 0 0 255
3 0 1 2
```

## 문제 해결 (Troubleshooting)

### 모델이 표시되지 않음
- PLY 파일이 올바른 형식인지 확인
- ASCII 형식의 PLY 파일인지 확인 (바이너리 형식은 지원되지 않음)
- 파일에 vertex와 face 데이터가 있는지 확인

### 모델이 너무 작거나 큼
- 마우스 휠로 줌 인/아웃 조정
- 모델의 실제 좌표계 크기 확인

### 회전이 부드럽지 않음
- 매우 큰 모델의 경우 성능 제한이 있을 수 있음
- 더 작은 폴리곤 수의 모델 사용 권장

### 색상이 표시되지 않음
- PLY 파일에 색상 속성(red, green, blue)이 포함되어 있는지 확인
- 없을 경우 기본 회색(128, 128, 128)으로 표시됩니다

## 키보드 단축키 (Keyboard Shortcuts)

현재 버전에서는 마우스 컨트롤만 지원됩니다. 키보드 단축키는 향후 버전에서 추가될 예정입니다.

## 추가 정보 (Additional Information)

더 자세한 정보는 다음 문서를 참조하세요:
- `README.md`: 프로젝트 개요 및 빠른 시작 가이드
- `ARCHITECTURE.md`: 소프트웨어 아키텍처 상세 설명
- `BUILD.md`: 빌드 및 컴파일 지침
