# OpenGL PLY Viewer - 문서 인덱스 (Documentation Index)

## 🎯 시작하기 (Getting Started)

처음 사용하시나요? 다음 순서대로 읽어보세요:

1. **[README.md](README.md)** - 프로젝트 소개 및 개요
2. **[QUICK_START.md](QUICK_START.md)** - 5분 빠른 시작 가이드 ⭐
3. **[UI_MOCKUP.txt](UI_MOCKUP.txt)** - 애플리케이션 화면 미리보기

## 📚 전체 문서 목록 (Complete Documentation)

### 사용자 가이드 (User Guides)
| 문서 | 설명 | 대상 |
|------|------|------|
| [QUICK_START.md](QUICK_START.md) | 5분 빠른 시작 튜토리얼 | 모든 사용자 ⭐ |
| [USAGE.md](USAGE.md) | 완전한 사용자 매뉴얼 | 일반 사용자 |
| [UI_MOCKUP.txt](UI_MOCKUP.txt) | ASCII 아트 UI 모형 | 시각적 참조 |

### 개발자 가이드 (Developer Guides)
| 문서 | 설명 | 대상 |
|------|------|------|
| [BUILD.md](BUILD.md) | 빌드 및 컴파일 가이드 | 개발자 ⭐ |
| [ARCHITECTURE.md](ARCHITECTURE.md) | 시스템 아키텍처 상세 | 개발자 |
| [UI_DESIGN.md](UI_DESIGN.md) | UI 디자인 명세서 | UI/UX 개발자 |

### 참조 문서 (Reference Documentation)
| 문서 | 설명 | 대상 |
|------|------|------|
| [PROJECT_SUMMARY.md](PROJECT_SUMMARY.md) | 종합 프로젝트 보고서 | 프로젝트 관리자 |
| [README.md](README.md) | 프로젝트 개요 | 모든 사용자 |

## 🗂 문서별 주요 내용 (Document Contents)

### 📘 README.md
- 프로젝트 소개
- 주요 기능 목록
- 빌드 요구사항
- 기본 사용법
- 프로젝트 구조 개요

### ⚡ QUICK_START.md
- 5단계 시작 가이드
- 5분 튜토리얼
- 빠른 문제 해결
- 샘플 파일 정보
- FAQ

### 📖 USAGE.md
- 상세 사용법
- UI 컨트롤 설명
- 카메라 조작 가이드
- 투영 모드 설명
- 고급 기능
- 완전한 문제 해결 가이드

### 🔨 BUILD.md
- 빌드 요구사항
- Visual Studio 설정
- 명령줄 빌드 방법
- 문제 해결
- 개발 환경 설정

### 🏗 ARCHITECTURE.md
- 시스템 구성 요소
- 클래스 구조
- 데이터 흐름
- 렌더링 파이프라인
- 기술 스택 상세

### 🎨 UI_DESIGN.md
- UI 레이아웃 상세
- 컨트롤 명세
- 사용자 인터랙션 플로우
- 색상 스킴
- 향후 개선 사항

### 🖼 UI_MOCKUP.txt
- ASCII 아트 UI 모형
- 투영 모드 비교 다이어그램
- 상호작용 플로우차트
- 샘플 모델 구조

### 📊 PROJECT_SUMMARY.md
- 완전한 프로젝트 보고서
- 코드 통계
- 클래스 다이어그램
- 알고리즘 설명
- 성능 특성
- 제한사항 및 확장성

## 🎓 학습 경로 (Learning Paths)

### 빠른 사용자 (Quick User)
```
README.md → QUICK_START.md → UI_MOCKUP.txt
```
**시간**: 10분  
**목표**: 바로 사용 시작

### 일반 사용자 (Regular User)
```
README.md → QUICK_START.md → USAGE.md → UI_MOCKUP.txt
```
**시간**: 30분  
**목표**: 모든 기능 숙지

### 개발자 (Developer)
```
README.md → BUILD.md → ARCHITECTURE.md → PROJECT_SUMMARY.md
```
**시간**: 1시간  
**목표**: 코드 이해 및 수정 가능

### 프로젝트 관리자 (Project Manager)
```
README.md → PROJECT_SUMMARY.md → ARCHITECTURE.md
```
**시간**: 45분  
**목표**: 프로젝트 전체 파악

### UI/UX 디자이너 (UI/UX Designer)
```
UI_MOCKUP.txt → UI_DESIGN.md → USAGE.md
```
**시간**: 30분  
**목표**: UI 구조 및 사용성 이해

## 📁 소스 코드 구조 (Source Code Structure)

### 핵심 클래스 (Core Classes)
```cpp
COpenGLTesterApp          // OpenGLTester.cpp/h
└─ COpenGLTesterDlg       // OpenGLTesterDlg.cpp/h
   └─ OpenGLRenderer      // OpenGLRenderer.cpp/h
      ├─ PLYLoader (1)    // PLYLoader.cpp/h
      └─ PLYLoader (2)    // PLYLoader.cpp/h
```

### 지원 파일 (Support Files)
```
pch.h/cpp                 // 프리컴파일 헤더
framework.h               // 프레임워크 includes
targetver.h               // Windows 버전
Resource.h                // 리소스 ID 정의
```

### 리소스 (Resources)
```
OpenGLTester.rc           // 리소스 스크립트
res/OpenGLTester.ico      // 애플리케이션 아이콘
res/OpenGLTester.rc2      // 추가 리소스
```

## 🧪 샘플 데이터 (Sample Data)

### sample_cube.ply
- **타입**: 컬러 큐브
- **버텍스**: 8개
- **면**: 12개 삼각형
- **용도**: 기본 렌더링 테스트

### sample_pyramid.ply
- **타입**: 컬러 피라미드
- **버텍스**: 5개
- **면**: 6개 삼각형
- **용도**: 다른 형태 비교

## 🔍 빠른 참조 (Quick Reference)

### 주요 버튼
- **Load PLY 1**: 첫 번째 모델 로드 (왼쪽 표시)
- **Load PLY 2**: 두 번째 모델 로드 (오른쪽 표시)

### 투영 모드
- **Perspective**: 원근감 있는 뷰 (기본)
- **Orthographic**: 직교 투영 뷰

### 마우스 컨트롤
- **좌클릭 + 드래그**: 회전
- **휠 위로**: 줌 인
- **휠 아래로**: 줌 아웃

### 지원 파일 형식
- **PLY**: ASCII 형식만 지원
- **버텍스 속성**: 위치, 색상, 노멀
- **면**: 삼각형 (자동 삼각화)

## 📞 도움말 (Help & Support)

### 문제가 있으신가요?

1. **빌드 문제** → [BUILD.md](BUILD.md) 문제 해결 섹션
2. **사용법 문제** → [USAGE.md](USAGE.md) 문제 해결 섹션
3. **코드 이해** → [ARCHITECTURE.md](ARCHITECTURE.md)
4. **프로젝트 개요** → [PROJECT_SUMMARY.md](PROJECT_SUMMARY.md)

### 자주 묻는 질문

**Q: 어디서부터 시작하나요?**  
A: [QUICK_START.md](QUICK_START.md)를 읽고 5분 튜토리얼을 따라하세요.

**Q: 빌드가 안 됩니다**  
A: [BUILD.md](BUILD.md)의 문제 해결 섹션을 확인하세요.

**Q: 코드를 수정하고 싶습니다**  
A: [ARCHITECTURE.md](ARCHITECTURE.md)로 구조를 이해한 후 수정하세요.

**Q: 어떤 기능이 있나요?**  
A: [README.md](README.md)와 [USAGE.md](USAGE.md)를 참조하세요.

## 🎯 다음 단계 (Next Steps)

### 처음 사용자
1. ✅ 이 문서를 읽었습니다
2. → [QUICK_START.md](QUICK_START.md)로 이동
3. → Windows에서 프로젝트 빌드
4. → 샘플 파일로 테스트

### 개발자
1. ✅ 이 문서를 읽었습니다
2. → [BUILD.md](BUILD.md)로 빌드 환경 설정
3. → [ARCHITECTURE.md](ARCHITECTURE.md)로 구조 파악
4. → 코드 수정 및 확장

## 📈 프로젝트 통계 (Project Statistics)

- **총 파일**: 27개
- **소스 코드**: 13개 (910 lines)
- **문서**: 8개 (1,200+ lines)
- **리소스**: 4개
- **샘플 데이터**: 2개
- **완성도**: 100%

## ⭐ 추천 읽기 순서 (Recommended Reading Order)

### 급한 사용자 (5분)
```
1. UI_MOCKUP.txt      (2분 - 화면 보기)
2. QUICK_START.md     (3분 - 바로 시작)
```

### 일반 사용자 (20분)
```
1. README.md          (5분 - 개요)
2. QUICK_START.md     (5분 - 시작)
3. USAGE.md          (10분 - 상세 기능)
```

### 개발자 (60분)
```
1. README.md          (5분 - 개요)
2. BUILD.md          (15분 - 빌드 설정)
3. ARCHITECTURE.md   (20분 - 구조 이해)
4. PROJECT_SUMMARY.md (20분 - 전체 파악)
```

---

## 📋 체크리스트 (Checklist)

프로젝트를 시작하기 전 확인:

- [ ] README.md를 읽었습니다
- [ ] QUICK_START.md를 읽었습니다
- [ ] Windows 환경이 준비되었습니다
- [ ] Visual Studio 2019+ 설치 완료
- [ ] MFC 라이브러리 설치 완료
- [ ] 샘플 PLY 파일을 확인했습니다

---

**마지막 업데이트**: 2025-11-17  
**버전**: 1.0.0  
**상태**: ✅ 완료

모든 문서를 보려면 프로젝트 루트 디렉토리에서 `.md` 또는 `.txt` 파일을 확인하세요.
