/*  (题目略)
    分治的技巧在于如何划分棋盘，使划分后的棋盘大小相同，并且每个子棋盘均包含一个特殊方格，从而减小题目规格
    对于划分后原先没有特殊方格的三个子方格，用一个L型骨牌覆盖这三个较小棋盘的汇合处。
    进行此划分策略直至分割为1×1的子棋盘 */

//(tr,tc)是棋盘中左上角的方格坐标
//(dr,dc)是特殊方格所在的坐标
//size是棋盘的行数或列数

int board[1025][1025];
static int tile=1;      //用到的L型骨牌个数
void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
    if(size==1) return;

    int t=tile++;
    int s=size/2;
    if(dr<tr+s&&dc<tc+s)
        ChessBoard(tr,tc,dr,dc,s);
    else
    {
        board[tr+s-1][tc+s-1]=t;
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }
    if(dr<tr+s&&dc>=tc+s)
        ChessBoard(tr,tc+s,dr,dc,s);
    else
    {
        board[tr+s-1][tc+s]=t;
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }
    if(dr>=tr+s&&dc<tc+s)
        ChessBoard(tr+s,tc,dr,dc,s);
    else
    {
        board[tr+s][tc+s-1]=t;
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }
    if(dr>=tr+s&&dc>=tc+s)
        ChessBoard(tr+s,tc+s,dr,dc,s);
    else
    {
        board[tr+s][tc+s]=t;
        ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }
}


