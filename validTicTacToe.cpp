
/**
 * ����һ���ַ������� board ��ʾ������Ϸ�����̡����ҽ����ھ�����Ϸ�����У������п��ܴﵽ board ����ʾ��״̬ʱ���ŷ��� true ��

������Ϸ��������һ�� 3 x 3 ���飬���ַ� ' '��'X' �� 'O' ��ɡ��ַ� ' ' ����һ����λ��

�����Ǿ�����Ϸ�Ĺ���

����������ַ������λ��' '���С�
��� 1 ���Ƿ��ַ� 'X' ������� 2 ���Ƿ��ַ� 'O' ��
'X' �� 'O' ֻ��������ڿ�λ�У���������ѷ����ַ���λ�ý�����䡣
���� 3 ����ͬ���ҷǿգ����ַ�����κ��С��л�Խ���ʱ����Ϸ������
������λ�÷ǿ�ʱ��Ҳ��Ϊ��Ϸ������
�����Ϸ��������Ҳ������ٷ����ַ���
?

ʾ�� 1��


���룺board = ["O  ","   ","   "]
�����false
���ͣ���� 1 ���Ƿ��ַ� "X" ��
ʾ�� 2��


���룺board = ["XOX"," X ","   "]
�����false
���ͣ����Ӧ���������ַ���
ʾ�� 3��


���룺board = ["XXX","   ","OOO"]
�����false

 * 
 * 
 * 
*/



class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = 0, oCount = 0;
        for (string & row : board) {
            for (char c : row) {
                xCount = (c == 'X') ? (xCount + 1) : xCount;
                oCount = (c == 'O') ? (oCount + 1) : oCount;
            }
        }
        if (oCount != xCount && oCount != xCount - 1) {
            return false;
        }
        if (win(board, 'X') && oCount != xCount - 1) {
            return false;
        }
        if (win(board, 'O') && oCount != xCount) {
            return false;
        }
        return true;
    }

    bool win(vector<string>& board, char p) {
        for (int i = 0; i < 3; ++i) {
            if (p == board[i][0] && p == board[i][1] && p == board[i][2]) {
                return true;
            }
            if (p == board[0][i] && p == board[1][i] && p == board[2][i]) {
                return true;
            }
        }
        if (p == board[0][0] && p == board[1][1] && p == board[2][2]) {
            return true;
        }
        if (p == board[0][2] && p == board[1][1] && p == board[2][0]) {
            return true;
        }
        return false;
    }
};