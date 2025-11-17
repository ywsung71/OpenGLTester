# OpenGLTester
MFC OpenGL PLY Viewer Application

## 기능 (Features)
- MFC 기반 OpenGL 3D 시각화 애플리케이션
- 두 개의 PLY 파일을 동시에 로드하고 시각화
- Orthographic(직교) 및 Perspective(원근) 투영 모드 전환
- 마우스로 회전 및 줌 컨트롤

## 빌드 요구사항 (Build Requirements)
- Visual Studio 2019 or later
- Windows SDK 10.0 or later
- MFC libraries

## 사용 방법 (Usage)
1. Visual Studio에서 OpenGLTester.sln 열기
2. 빌드 및 실행
3. "Load PLY 1" 버튼으로 첫 번째 PLY 파일 로드
4. "Load PLY 2" 버튼으로 두 번째 PLY 파일 로드
5. Orthographic/Perspective 라디오 버튼으로 투영 모드 변경
6. 마우스 왼쪽 버튼 드래그로 회전
7. 마우스 휠로 줌 인/아웃

## 테스트 파일 (Test Files)
프로젝트에 포함된 샘플 PLY 파일:
- sample_cube.ply - 컬러 큐브
- sample_pyramid.ply - 컬러 피라미드

## 프로젝트 구조 (Project Structure)
- OpenGLTester.cpp/h - 메인 애플리케이션 클래스
- OpenGLTesterDlg.cpp/h - 메인 다이얼로그 클래스
- OpenGLRenderer.cpp/h - OpenGL 렌더링 클래스
- PLYLoader.cpp/h - PLY 파일 파서
- Resource.h/OpenGLTester.rc - UI 리소스 정의
