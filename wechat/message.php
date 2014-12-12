<?php

class Message
{
    private $msg_head;
    private $msg_tail;
    private $array_msg_template;
    private $from_user;
    private $to_user;

    public function Message($from, $to)
    {
        $this->from_user = $from;
        $this->to_user   = $to;

        $this->msg_head = "<xml>
                    <ToUserName><![CDATA[%s]]></ToUserName>
                    <FromUserName><![CDATA[%s]]></FromUserName>
                    <CreateTime>%s</CreateTime>
                    <MsgType><![CDATA[%s]]></MsgType>";

        $this->msg_tail = "</xml>";

        $this->array_msg_template = array(
                "text" => "
                    <Content><![CDATA[%s]]></Content>",
                "image" => "
                    <Image>
                    <MediaId><![CDATA[%s]]></MediaId>
                    </Image>",
                "voice" => "
                    <Voice>
                    <MediaId><![CDATA[%s]]></MediaId>
                    </Voice>",
                "video" => "
                    <Video>
                    <MediaId><![CDATA[%s]]></MediaId>
                    <Title><![CDATA[%s]]></Title>
                    <Description><![CDATA[%s]]></Description>
                    </Video>",
                "music" => "
                    <Music>
                    <Title><![CDATA[%s]]></Title>
                    <Description><![CDATA[%s]]></Description>
                    <MusicUrl><![CDATA[%s]]></MusicUrl>
                    <HQMusicUrl><![CDATA[%s]]></HQMusicUrl>
                    <ThumbMediaId><![CDATA[%s]]></ThumbMediaId>
                    </Music>
                    ",
                "news" => "
                    <item>
                    <Title><![CDATA[%s]]></Title> 
                    <Description><![CDATA[%s]]></Description>
                    <PicUrl><![CDATA[%s]]></PicUrl>
                    <Url><![CDATA[%s]]></Url>
                    </item>
                    ");
    }

    public function FormatTextMessage($content)
    {
        $str_template = $this->msg_head.$this->array_msg_template["text"].$this->msg_tail;

        return sprintf($str_template, $this->to_user, $this->from_user, time(), "text", $content);
    }

    public function FormatImageMessage($media_id)
    {
        $str_template = $this->msg_head.$this->array_msg_template["image"].$this->msg_tail;

        return sprintf($str_template, $this->to_user, $this->from_user, time(), "image", $media_id);
    }

    public function FormatVoiceMessage($media_id, $title, $description)
    {
        $str_template = $this->msg_head.$this->array_msg_template["voice"].$this->msg_tail;

        return sprintf($str_template, $this->to_user, $this->from_user, time(), "voice", $media_id, $title, $description);
    }

    public function FormatVideoMessage($media_id, $title, $description)
    {
        $str_template = $this->msg_head.$this->array_msg_template["video"].$this->msg_tail;

        return sprintf($str_template, $this->to_user, $this->from_user, time(), "video", $media_id, $title, $description);
    }

    public function FormatMusicMessage($title, $description, $music_url, $hq_music_url, $thumb_media_id)
    {
         $str_template = $this->msg_head.$this->array_msg_template["music"].$this->msg_tail;

        return sprintf($str_template, $this->to_user, $this->from_user, time(), "music", $title, $description, $music_url, $hq_music_url, $thumb_media_id);
    }

    public function FormatNewsMessage($array_news)
    {
        $count = count($array_news);
   
        $items = sprintf($this->msg_head."<ArticleCount>%d</ArticleCount><Articles>",$this->to_user, $this->from_user, time(), "news", $count);
   
        for($i = 0; $i < $count; $i++)
        {
            $items = $items.sprintf($this->array_msg_template["news"], $array_news[$i]["title"], $array_news[$i]["description"], $array_news[$i]["pic_url"], $array_news[$i]["url"]);
        }
   
        $items = $items."</Articles>".$this->msg_tail;
    
        return $items;
    }
}
?>
