/**
 * @file Direct_Main.h
 * @brief DirectX�̃I�u�W�F�N�g��f�o�C�X�Ɋւ���v���g�^�C�v�錾�������Ă�
 * @author �ēc�N��
 * @date 2016�N7��1��
 */

#ifndef DIRECT_MAIN
#define DIRECT_MAIN

////////////////////////////////////////////
// �g�p����֐��̃v���g�^�C�v�錾
////////////////////////////////////////////

/// DirectX�̏������֐�
/**
 * @attention ���̊֐���WinMain�ɏ���
 * @param [in] _hWnd		�E�B���h�E�E�n���h��
 * @retval S_OK �f�o�C�X�̐����ɐ���
 * @retval E_FAIL �f�o�C�X�̐����Ɏ��s
*/
HRESULT Init_Direct(HWND _hWnd);

/// �I�u�W�F�N�g�̉���֐�
/**
 * @attention ���̊֐���WinMain�ɏ���
 * @return �Ȃ�
 */
void Free();


#endif