/**
 * @file GameSceneCntrol.h
 * @breif �Q�[���S�̂̑���Ɋ֌W�����`�E�v���g�^�C�v�錾�������Ă���
 * @author �ēc�N�ǁA�R�{�ϑ��Y�A�ݖ{��́A����G���A�c���M��A�|���ĕ��A�ѓc����
 * @date 2016�NX��Y��
 */

////////////////////////////////////////////////
// ��`
////////////////////////////////////////////////

/// �L�����N�^�[�ړ����x
#define MOVE_SPEED 5

////////////////////////////////////////////////
// �g�p����֐��̃v���g�^�C�v�錾
////////////////////////////////////////////////

/// 60fps�Ń��[�v�����鑀��֐�
/**
 * @return �Ȃ�
 */
void Control();

/// �����蔻��̊֐�
/**
 * @param [in] _x x���W
 * @param [in] _y y���W
 * @param [in] _sx �`�悷��L������X���̃`�b�v�̐�
 * @param [in] _sy �`�悷��L������Y���̃`�b�v�̐�
 * @retval true 
 * @retval false 
 */
bool Collision_Check(float _x, float _y, int _sx, int _sy);

