        // Câu 1.
        // /<[^>]+>/ : chuỗi bắt đầu băng '<', theo sau là ít nhất một ký tự bki ngoại trừ '>', và kết thúc bằng '>'
        // <an xml tag>  Đúng 
        // <opentag> <closetag> Sai do có '>' trong chuỗi
        // </closetag> Đúng
        // <> Sai do ko có ký tự nào giữa '<' và '>'
        // <with attribute=”77”>  Đúng
        
        // Câu 2.
        // /a.[bc]+/ : + ký tự 'a' sẽ đi kèm với bki một ký tự nào 
        //             + một chuỗi có ít nhất một ký tự b hoặc c
        // abc Đúng 
        // abbbbbbbb Đúng
        // azc Đúng do a sẽ đi với kí tự 'z' và 'c' được lặp 1 lần
        // abcbcbcbc Đúng
        // ac Sai do 'c' đi với a, nên [bc]+ sẽ là rỗng => ko hợp lệ 
        // azccbbbbcbccc Đúng do a đi với 'c', còn lại là lặp 
        
        // Câu 3.
        // /(very )+(fat )?(tall|ugly) man/ :
        // + Lăp lại ít nhất một lần "very "
        // + Có hoặc ko xuất hiện "fat "
        // + Chọn "tall" hoặc "ugly"
        // + theo sau " man"
        // very fat man Sai do ko xuất hiện "tall" hay "ugly"
        // fat tall man Sai do ko có "very"
        // very very fat ugly man Đúng 
        // very very very tall man Đúng
        
        // Câu 4.
        // abc.def.ghi.jkx
        // ^.{3}\..{3}\..{3}\..{3}$
        // + ^...$ : đảm bảo cho chuỗi phải luôn giống mẫu
        // + .{3}: 3 kí tự bki trừ newline
        // + .\ : dấu chấm thực sự
        
        // Câu 5.
        // ^(\(\d{3}\)|\d{3})[ .-]?\d{3}[ .-]?\d{4}$
        // + ^...$ đảm bảo chuỗi luôn giống dạng mẫu 
        // + \d{3} : ba chữ số
        // + (\(\d{3}\)|\d{3}) : ba chữ số, có thể có ngoặc
        // + [ .-]? : dấu cách, dấu chấm hoặc gạch ngang (có hoặc không)
        // + \d{4} : bốn chữ số cuối
        
        // Câu 6.
        // Yêu cầu : 
        // +Chỉ gồm chữ hoa, chữ thường, số
        // +Có thể có dấu cách, gạch ngang -, gạch dưới _ làm bộ phân tách
        // +Không có hai bộ phân tách liền nhau
        // +Không bắt đầu hoặc kết thúc bằng bộ phân tách
        // ^[A-Za-z0-9]+(?:[ _-][A-Za-z0-9]+)*$
        // + [A-Za-z0-9]+ : một hoặc nhiều ký tự số và chữ
        // + [ _-] dấu phân cách hợp lệ ' ', '_', '-' chỉ 1 trong 3 kí tự này 
        // + [A-Za-z0-9]+: phải tiếp nối bằng ít nhất một ký tự chữ hoặc số
        // + (...)* lặp lại 0 hoặc nhiều lần 
        
