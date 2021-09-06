## FlipFlop SDK for IOS

Live Commerce IOS SDK

## 요구사항
* iOS 12.0+
* Xcode 12+
* Swift 5.4+

## 설치
### CocoaPods
    target ‘YourProject’ do
        use_frameworks!

        # Pods for FlipFlopSDK
        pod 'FlipFlopSDK', '0.1.0'
    
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
streamer.prepare(preview: UIView, config: FlipFlopSDK.FFStreamerConfig = FFStreamerConfig())

// 방송을 시작합니다. 방송 타이틀과 내용 입력. onPrepared 이후에 호출해야 함
streamer.start(sdk: FlipFlopSDK.FlipFlop, streamkey: String, livekey: String)

// 방송을 종료합니다.
streamer.stop()

// 라이브 방송 객체 메모리 해제
streamer.reset()

// 카메라 변경
streamer.switchCamera()

// 채팅 일반메시지 보내기
streamer.sendMessage(text: String, data: String? = nil, customType: String? = nil)
// 채팅 귓속말 보내기
streamer.sendWhispher(receiver: String, text: String, data: String? = nil, customType: String? = nil)
// 채팅 명령형 메시지 보내기
streamer.sendCommand(text: String, data: String? = nil, customType: String? = nil)
// 카메라 좌우 반전
streamer.videoMirror(mirror: Bool)
// 카메라 줌
streamer.zoom(factor: CGFloat)
// 영상 사진 pip 기능. 오른쪽 상단에 카메라 영상이 노출되며 크기는 scale로 조절
streamer.setBackground(backgroundImage: UIImage?, scale: CGFloat = 0.25)
// 카메라 필터 
streamer.setFilter(filter: FlipFlopSDK.VideoFilter)
// gif 플레이
streamer.playGif(named: String, completion: (() -> Void)?) throws
// 오디오 묵음
streamer.mute(on: Bool)
// 카메라 수동 포커스
streamer.setPointOfInterest(focus: CGPoint)
// 카메라 수동 노출
streamer.setPointOfInterest(exposure: CGPoint)

```

### VideoFilter 
```swift
public enum VideoFilter {
    case none
    case sephia(value: Float)
    case blendMaks(overlayImage: CIImage, maskImage: CIImage)
    case sourceOverComposit(overlayImage: CIImage)
    case colorOverlay(color: UIColor)
    case custom(effect: VideoEffect)
}
```

### Streamer Property
```swift
    
    var chatHeartbitTime: Double
    // 자동 카메라 오토포커스 true / false ( default false)
    var continuousAutofocus: Bool
    // 자동 카메라 노출 true / false ( default false)
    var continuousExposure: Bool
    // 카메라 노출 bias (minExposureTargetBias ~ maxExposureTargetBias)
    var exposureTargetBias: Float
    // 디바이스 최소 카메라 노출 bais
    var minExposureTargetBias: Float { get }
    // 디바이스 최대 카메라 노출 bais
    var maxExposureTargetBias: Float { get }
    // 현재 설정 된 비트레이트
    var currentBitrate: Int { get }
    // 방송 중 bitrate변경 시 호출 (bps)
    var videoBitrateOnFly: Int
    // adaptive bitrate true / false (default false)
    var adaptiveBitrate: Bool
```

### 라이브 방송 이벤트 콜백
```swift
public protocol FFStreamerDelegate: class { {
    
    // 방송 준비 이벤트
    func onPrepared()
    // 방송 시작 이벤트
    func onStarted()
    // 방송 중지 이벤트
    func onStopped()
    // 방송 종료 이벤트
    func onCompleted()
    // 방송 채팅 메시지 이벤트
    func onChatMessgeReceived(message: FFMessage)
    // 방송 에러 이벤트
    func onError(error: FFError)
    // 스트림 정보 이벤트
    func onStreamStatus(notification: Notification)
    // bandwidth가 부족할때 발생하는 이벤트
    func onInSufficentBW()
    // bandwidth가 다시 충분해 졌을때 발생하는 이벤트
    func onSufficentBW()
    // 비트레이트가 변경되었을때 발생하는 이벤트
    func onVideoBitrateChanged(newBitrate: Int)
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
    // 백그라운드로 진입 이벤트
    func onBackground(player: FFPlayer)
    // 포그라운드로 진입 이벤트
    func onForeground(player: FFPlayer)
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
