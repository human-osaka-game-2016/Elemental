/**
 * @file Direct_Draw.h
 * @brief DirectX�̕`��Ɋ֌W�����`�E�^�E�v���g�^�C�v�錾�������Ă���
 * @author �ēc�N��
 * @date 2016�N7��1��
 */

#ifndef DIRECT_DRAW
#define DIRECT_DRAW

////////////////////////////////////////////
// �^
////////////////////////////////////////////

/// ���W�E�F����
struct CUSTOMVERTEX
{
	FLOAT	m_x;		///< ��ʂɕ\������e�N�X�`����x���W
	FLOAT	m_y;		///< ��ʂɕ\������e�N�X�`����y���W
	FLOAT	m_z;		///< ��ʂɕ\������e�N�X�`����z���W
	FLOAT	m_rhw;		///< �������W
	DWORD	m_color;	///< �F����
	FLOAT	m_tu;		///< �e�N�X�`�����̂�x���W
	FLOAT	m_tv;		///< �e�N�X�`�����̂�y���W
}; 

////////////////////////////////////////////
// �g�p����֐��̃v���g�^�C�v�錾
////////////////////////////////////////////

/// �`��̏������֐�
/**
 * @attention ���̊֐���WinMain�ɏ���
 * @return �Ȃ�
*/
void Init_Draw();

/// �`��n�߂̊֐�
/**
 * @return �Ȃ�
 */
void Draw_Start();

/// �`��֐�
/**
 * ��ʂɕ`�悷�邽�߂̏���
 * @param [in] _pTexture  �ݒ肷��e�N�X�`���������ɏ���
 * @param [in] _setdraw[] �ǂ��Ƀe�N�X�`����ݒ肷�邩���w�肷��
 * @return �Ȃ�
 */
void Draw_Display(LPDIRECT3DTEXTURE9   _pTexture, CUSTOMVERTEX _setdraw[]);

/// �摜�t�@�C���̃��[�h
/**
 * @attention ���̊֐���WinMain�ɏ���
 * @param[in]	_filePath	�ǂݍ��މ摜�t�@�C����
 * @param[out]	_ppTexture	�ǂݍ��񂾉摜���ǂ��ɕ`�悷�邩���w�肷��
 * @retval S_OK		�ǂݍ��ݐ���
 * @retval E_FAIL	�ǂݍ��ݎ��s
*/
HRESULT Load_Texture(TCHAR _filePath[256], LPDIRECT3DTEXTURE9* _ppTexture);

/// �摜�t�@�C���̃��[�h(�ڍה�)
/**
 * �摜���[�h����Load_Texture()�����ڍׂȐݒ���������Ƃ��Ɏg��
 * @attention ���̊֐���WinMain�ɏ���
 * @param[in]  _filepath		�ǂݍ��މ摜�t�@�C����
 * @param[out] _ppTexture		�ǂݍ��񂾉摜���ǂ��ɕ`�悷�邩���w�肷��
 * @retval S_OK		�ǂݍ��ݐ���
 * @retval E_FAIL	�ǂݍ��ݎ��s
 */
HRESULT Load_Texture_EX(TCHAR _filePath[256], LPDIRECT3DTEXTURE9* _ppTexture);

/// �`��I���̊֐�
/**
 * @return �Ȃ�
 */
void Draw_End();

/// DirectX�̃f�o�C�X�����̊֐�
/**
 *  ���̊֐���Main.h�ŌĂяo���Ă�
 * @param [in] _pDirect3D		DirectX�I�u�W�F�N�g�̃|�C���^
 * @param [in] _hWnd			�E�B���h�E�E�n���h��
 * @retval S_OK		�ǂݍ��ݐ���
 * @retval E_FAIL	�ǂݍ��ݎ��s
 */
HRESULT Create_Direct_Device(IDirect3D9* _pDirect3D, HWND _hWnd);

/// �`��̉���֐�
/**
* �`��Ŏg���Ă�I�u�W�F�N�g��������Ă���
* @return �Ȃ�
*/
void Draw_Free();

#endif