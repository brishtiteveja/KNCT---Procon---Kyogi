Windows 7 Proで開発・動作確認し、ubuntu11.04でも動作確認しました。


問題をダウンロードする
http://server-name/GetProblem?ProblemNumber=xxx

プレイヤーID(回答者を識別するトークン)が有効か確認する
http://server-name/CheckParameters?PlayerID=xxx

回答を提出する
http://server-name/SubmitAnswer?PlayerID=xxx&ProblemNumber=xxx
(POSTデータとして回答を付加する)

