## FlipFlop SDK for IOS

Live Commerce IOS SDK

## 요구사항
* iOS 11.0+
* Xcode 11+
* Swift 4.2+

## 설치
### CocoaPods
    target ‘YourProject’ do
        use_frameworks!

        # Pods for FlipFlopSDK
        pod 'FlipFlopSDK'
    
    end
### 권한 설정
아래 권한들을 info.plist에 입력해주세요
    
    Privacy - Bluetooth Always Usage Description      
    Privacy - Camera Usage Description
    Privacy - Microphone Usage Description

### 빌드 설정
    Build Settings > Build Options > Enable Bitcode 옵션을 No로 설정

## 사용법
### 라이브러리 초기화

https://wwww.flipflop.tv 에서 발급받은 appKey 와 appSecret을 입력해주세요

```swift
// Initialize SDK
FlipFlop.initialize(appKey: APP_KEY, appSecret: APP_SECRET)
```

### 라이브러리 인증

중복되지 않은 userID를 입력하세요. 
userName과 avatarProfileURL은 선택사항입니다.
인증에 성공하게 되면 사용할 수 있는 라이브러리 인스턴스를 반환합니다.

```swift
FlipFlop.authentication(userID: USER_ID, userName: USER_NAME, avatarProfileURL: AVATAR_PROFILE_URL) { (result) in
    switch result {
    case .failure(let error):
        // error
    case .success(let sdk):
        // success result is flipflop instance
    }
}
```

### 유저 정보 업데이트
```swift
sdk.updateUserInfo(userName: "Updated User") { (result) in
    switch result {
    case .failure(let error):
    case .success:
    }
}
```

### 라이브 방송 하기
```swift
// 라이브 방송 객체 생성
let streamer = sdk.getStreamer()
// 라이브 방송 이벤트 콜백 등록
streamer.delegate = self

// 카메라프리뷰 및 마이크 시작 및 방송 준비
streamer.prepare(preview: preview)

// 방송을 시작합니다. 방송 타이틀과 내용 입력. onPrepared 이후에 호출해야 함
streamer.start(title: TITLE, content: CONTENT)

// 방송을 종료합니다.
streamer.stop()

// 라이브 방송 객체 메모리 해제
streamer.reset()

// 카메라 변경
streamer.switchCamera()
```

### 라이브 방송 이벤트 콜백
```swift
public protocol FFStreamerDelegate: class { {
    
    // 방송 준비 이벤트
    func onPrepared()
    // 방송 시작 이벤트
    func onStarted(streamName: String)
    // 방송 중지 이벤트
    func onStopped()
    // 방송 종료 이벤트
    func onCompleted()
    // 방송 채팅 메시지 이벤트
    func onChatMessgeReceived(message: FFMessage)
    // 방송 에러 이벤트
    func onError(error: FFError)
}
```
### 방송 보기
```swift
// 플레이어 객체 생성
let player = sdk.getPlayer(videoKey: VIDEO_KEY)

// 플레이어 준비
player.prepare(view: playerView)

// 플레이어 시작. onPrepared 이후 호출
player.start()

// 플레이어 중지
player.stop()

// 플레이어 객체 메모리 해제
player.reset()

// 채팅 보내기
player.sendMessage(text: "Blar Blar Blar....")

// 채팅 히스토리 가져오기
player.getChatHistory { (result) in
    switch result {
    case .failure(let error):
    case .success(let messages):
    }
}

// 비디오 seek
player.seekTo(percent: 0.5)
```
### 방송 보기 이벤트 콜백
```swift
 public protocol FFPlayerDelegate {
     // 앱이 백그라운드 진입했을때
    func onBackground(player: FFPlayer)
    // 앱이 포그라운드 진입했을때
    func onForeground(player: FFPlayer)
    // 방송 준비 이벤트
    func onPrepared(player: FFPlayer)
    // 방송 시작 이벤트
    func onStarted(player: FFPlayer)
    // 방송 임시 정지 이벤트
    func onPaused(player: FFPlayer)
    // 방송 일시 정지 후 다시 시작 이벤트
    func onResumed(player: FFPlayer)
    // 방송 중지 이벤트
    func onStopped(player: FFPlayer)
    // 방송 종료 이벤트
    func onCompleted(player: FFPlayer)
    // 방송 진행 상태 이벤트
    func onProgressUpdated(player: FFPlayer, mSec: UInt64)
    // 방송 탐색 완료 이벤트
    func onSeekCompleted(player: FFPlayer, mSec: UInt64)
    // 방송 에러 이벤트
    func onError(player: FFPlayer, error: FFError)
    // 방송 채팅 메시지 이벤트
    func onChatMessgeReceived(message: FFMessage)
}
```

### 비디오 리스트 가져오기

비디오 리스트로더를 이용하여 next 함수 호출시 비디오 리스트를 가져옴
더 이상 가져올 비디오가 없으면 빈 배열이 내려옴

```swift
let loader = sdk.getVideoListLoader()
loader.next {(videoResult) in
        switch videoResult {
        case .failure(let error):
            // error
        case .success(let videos):
            // If there are no more, the count is zero.
        }
    }
}
```
### 비디오 정보 변경하기

비디오 타이틀과 내용을 변경한다.

```swift
sdk.editVideo(videoKey: VIDEO_KEY, title: "New Title", content: "New Content") {
    switch result {
    case .failure(let error):
    case .success:
    }
}
```    

### 비디오 비공개하기

visibility는 'public'또는 'private'만 허용됩니다. 기본값은 'public'입니다
```swift
sdk.editVideo(videoKey: VIDEO_KEY, visibility: "private") {
    switch result {
    case .failure(let error):
    case .success:
    }
}
```

### 비디오 삭제하기

비디오 삭제한다.

```swift
sdk.deleteVideo(videoKey: VIDEO_KEY) { (result) in
    switch result {
    case .failure(let error):
    case .success:
    }
}
```
    
    
## License 
MIT
