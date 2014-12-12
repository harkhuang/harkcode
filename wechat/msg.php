<?php
/**
  * wechat php test
  */

//define your token
include "message.php";

define("TOKEN", "chaoxiao6");
define ("HOST", "http://www.cpp01.com/weixin");

$wechatObj = new Service();
$wechatObj->valid();
$wechatObj->responseMsg();

class Service
{
    private $msg;
	public function valid()
    {
        $echoStr = $_GET["echostr"];

        //valid signature , option
        if($this->checkSignature()){
        	echo $echoStr;
        	//exit;
        }
    }

    public function log($str)
    {
        $fd = fopen("log.txt", "a+");
        if($fd)
        {
            fputs($fd, $str);
            fclose($fd);
        }
    }

    public function Help()
    {
        echo $this->msg->FormatTextMessage("1:显示分类\n2:笑话集锦\n3:游戏推荐");
    }

    public function Menu()
    {                
        $news = array(
                0 =>array(
                    "title" => "小6为您服务", 
                    "description" => "Main", 
                    "pic_url" => HOST."/image/logo.jpg",
                    "url" => HOST."/main.php"),
                1 =>array(
                    "title" => "合作餐厅", 
                    "description" => "这是测试信息1", 
                    "pic_url" => HOST."/image/logo.jpg",
                    "url" => "http://www.cpp01.com/info.php"),
                2 =>array(
                    "title" => "合作宾馆", 
                    "description" => "这是测试信息1", 
                    "pic_url" => HOST."/image/logo.jpg",
                    "url" => "http://www.cpp01.com/info.php"),
                3 =>array(
                    "title" => "合作商店", 
                    "description" => "这是测试信息1", 
                    "pic_url" => HOST."/image/logo.jpg",
                    "url" => "http://www.cpp01.com/info.php")
                );
        echo $this->msg->FormatNewsMessage($news);
    }

    public function Joke()
    {
        echo $this->msg->FormatTextMessage("该功能正在开发中,请耐心等待...[亲亲]");
    }

    public function Game()
    {
        $games = array(
                    0 => array(
                        "title" => "天天酷跑",
                        "description" => "天天酷跑是一款动作跑酷游戏",
                        "pic_url" => HOST."/image/ttkp.jpg",
                        "url" => "https://itunes.apple.com/cn/app/tian-tian-ku-pao/id653350791?mt=8"
                        ),
                    1 => array(
                        "title" => "我叫MT",
                        "description" => "一款非常火爆的卡牌游戏",
                        "pic_url" => HOST."/image/mt.jpg",
                        "url" => "https://itunes.apple.com/cn/app/wo-jiaomt-online/id560104652?mt=8"
                        )

                );
        echo $this->msg->FormatNewsMessage($games);
    }
    public function responseMsg()
    {
		$postStr = $GLOBALS["HTTP_RAW_POST_DATA"];

		if (!empty($postStr)){
              	$postObj = simplexml_load_string($postStr, 'SimpleXMLElement', LIBXML_NOCDATA);
                $fromUsername = $postObj->FromUserName;
                $toUsername = $postObj->ToUserName;
                $keyword = trim($postObj->Content);

                $this->msg = new Message($toUsername, $fromUsername);

                if($keyword == "1")
                {
                    $this->Menu();
                }
                else if($keyword == "2")
                {
                    $this->Joke();
                }
                else if($keyword == "3")
                {
                    $this->Game();
                }
                else
                {
                    $this->Help();
                }
        }
        else
        {
        	echo "";
        	exit;
        }
    }
		
	private function checkSignature()
	{
        $signature = $_GET["signature"];
        $timestamp = $_GET["timestamp"];
        $nonce = $_GET["nonce"];	
        		
		$token = TOKEN;
		$tmpArr = array($token, $timestamp, $nonce);
		sort($tmpArr, SORT_STRING);
		$tmpStr = implode( $tmpArr );
		$tmpStr = sha1( $tmpStr );
		
		if( $tmpStr == $signature ){
			return true;
		}else{
			return false;
		}
	}
}

?>

