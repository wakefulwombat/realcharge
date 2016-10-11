*ここにあるのはVisual Studio用プロジェクトファイルとソースコードのみです．*
*ライブラリ，画像音楽等素材は含まれておりません．*

# 現充爆奇譚  Real Charge Explosion  
ジャンル:被弾型アクション弾幕STG  
作者:wakefulwombat(タンタル)   


###ストーリー  
脈梨は天国でも相変わらずモテない生活をしていた．  
暇を持て余した脈梨は，ふと親友の縁内の生活が気になって地上をのぞいてみることにした．  
脈梨は死ぬ前に，縁内とある約束をしていた．それは，俺たちは一生童貞を貫こうというものであった．  
縁内はそのことを思い出し，今でも彼女がいないのかどうかを確かめようとしたのだ．  
ところが，なんということでしょう．  
縁内は高校で，女子に囲まれるモテモテの生徒会長になってしまっていたのだ．  
脈梨は激怒した．  
今，脈梨の復讐が始まる！

###初期キーコンフィグ  
・共通項目  
z:決定(ボスとの会話を一つ進める)  
x:キャンセル(ボスとの会話をスキップする)  
p:ポーズ画面   

・エクスプロード  
z:誘爆剤  
x:イグニッション  
c:チャージショット  
SHIFT:低速移動

・スタンド  
z:シャビーショット  
x:フレックス  
c:ホールド  
SHIFT:低速移動

・アブソーブ  
z:アブソーブ   
x:トランス  
c:コラプサー  
SHIFT:低速移動


ゲームパッドにも対応しています．
USB経由で接続後，ゲームを起動すれば操作方法は自動的に切り替わります．

ゲーム内メニュー画面のキーコンフィグ設定で，可能な限り任意のキーを設定できます．
キーボード，ゲームパッド両方の設定が可能で，接続状態に応じて自動で切り替わります．
その際実行ファイルを含むフォルダ内にキーコンフィグ用のファイルが出来上がります．
初期状態に戻したい場合は，このファイル(config.dat)を削除してください．

*注意*  
本ゲームでは，一つのキーに複数の役割を持たせられる仕様です．
初期状態でのプレイは推奨しません．キーコンフィグを行うようにしてください．

###チュートリアル  
本ゲームでは３つのモードを選べます。  
１．エクスプロードモード  
２．スタンドモード  
３．アブソーブモード  

原則として、敵が発射する弾やレーザーに当たってしまうとミス扱いとなります。

・エクスプロードでの遊び方  
イグニッションキーを押して、受付状態を表す白いリングがプレイヤーの周りに表れている瞬間に被弾してください。  
爆発します。  

誘爆剤は爆発とぶつかると新たな爆発を生み出します。

チャージショットは、弾やレーザーと衝突すると爆発し、敵にはダメージを与えます。チャージショットが貫通するか、消滅するかは色によって分かれており、パワーを多くためておくほど貫通する個体が増えます。  
チャージショットについては最低でも１００のパワーをためていないと発射できず、一度発射するとパワーは０になります。  


・スタンドモードでの遊び方  
フレックスキーを押し続けると、緑のリングがプレイヤーの周りに表れます。  
ホールドキーを押し続けると、赤のリングがプレイヤーの周りに表れます。  
キーを離したときに、リングの中にあった弾やレーザーを、攻撃レーザーに変換するか、一定時間固定することができます。  

シャビーショットは威力の弱いショットです。  

・アブソーブモードでの遊び方  
アブソーブ中はプレイヤーの周りに白いリングが現れます。この間に敵の弾やレーザーに被弾することでパワーをためることができます。白いリングが消えてから被弾するとミスになるので、切り替わるタイミングに注意してください。  
トランスキーを押すと、パワーを減らしながら攻撃レーザーを発射します。  
コラプサーキーを押すと、複数のエネルギー吸収体が現れ、敵の弾やレーザーとぶつかるとエネルギーとして吸収してくれます。  


###インストール，アンインストール方法  
zipを解凍してください．  
不要になればゴミ箱へ捨ててください。

###使用ライブラリ
DXライブラリ  
GuruGuruSMF  

###開発環境  
windows 7 , windows 8.1 , windows 10  
VisualStudio2013  

###ライセンス  
(The MIT License)
Copyright (c) 2015 wakefulwombat

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the 'Software'), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
