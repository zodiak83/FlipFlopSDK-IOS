## FlipFlop SDK for IOS

Live Commerce IOS SDK

## Requirements
* iOS 11.0+
* Xcode 11+
* Swift 5.0+

## Installation
### CocoaPods
    target ‘YourProject’ do
        use_frameworks!

        # Pods for FlipFlopSDK
        pod 'FlipFlopSDK'
    
    end
### Add Permission
Add below permissions to info.plist
    
    Privacy - Bluetooth Always Usage Description      
    Privacy - Camera Usage Description
    Privacy - Microphone Usage Description

## Tutorial
### Initialize
```swift
// Initialize SDK
FlipFlop.initialize(appKey: APP_KEY, appSecret: APP_SECRET)

FlipFlop.authentication(userID: USER_ID, userName: USER_NAME, avatarProfileURL: AVATAR_PROFILE_URL) { (result) in
    switch result {
    case .failure(let error):
        // error
    case .success(let sdk):
        // success result is flipflop instance
        sdk.
    }
}
```

### Streamer
```swift
let streamer = sdk.getStreamer()
streamer.delegate = self

// start preview
streamer.prepare(preview: preview)

// start publish after onPrepared on streamer 
streamer.start(title: TITLE, content: CONTENT)

// stop publish
streamer.stop()

// release 
streamer.reset()
```
### Streamer Delegate
```swift
extension StreamerViewController: FFStreamerDelegate {
    
    func onPrepared() {
    }
    func onStarted(streamName: String) {
    }
    func onStopped() {
    }
    func onCompleted() {
    }
    func onChatMessgeReceived(message: FFMessage) {
        
        switch message.type {
        case .join:
        // join user
        case .leave:
        // leave user
        case .msg:
        // receive mesassge
        default:
            break
        }
    }
    func onError(error: FFStreamerError) {
    }
}
```
### Player
```swift
let player = sdk.getPlayer(videoKey: VIDEO_KEY)
// load player
player.prepare(view: playerView)

// start after onPrepared on player
player.start()

// stop player
player.stop()

// release
player.reset()
```
### Player Delegate
```swift
 extension PlayerViewController: FFPlayerDelegate {
    func onBackground(player: FFPlayer) {
    }
    
    func onForeground(player: FFPlayer) {
    }
    func onPrepared(player: FFPlayer) {
    }
    func onStarted(player: FFPlayer) {
    }
    func onPaused(player: FFPlayer) {
    }
    func onResumed(player: FFPlayer) {
    }
    func onStopped(player: FFPlayer) {
    }
    func onCompleted(player: FFPlayer) {
    }
    func onProgressUpdated(player: FFPlayer, mSec: UInt64) {
    }
    func onSeekCompleted(player: FFPlayer, mSec: UInt64) {
    }
    func onError(player: FFPlayer, error: FFPlayerError) {
    }
    func onChatMessgeReceived(message: FFMessage) {
        
        switch message.type {
        case .join:
        // join user
        case .leave:
        // leave user
        case .msg:
        // receive mesassge
        default:
            break
        }
    }
    func onError(error: FFPlayerError) {
    }
}
```

### Get Video List
```swift
let loader = sdk.getVideoListLoader()
loader.next {(videoResult) in
        switch videoResult {
        case .failure(let error):
            // error
        case .success(let videos):
            // get video list
        }
    }
}
```    
    
    
    
## License 
MIT
