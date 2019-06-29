import React from 'react';
import {
  StyleSheet, View, Modal, Dimensions, StatusBar,
} from 'react-native';
import PropTypes from 'prop-types';
import Colors from '../common/Colors';

const { width } = Dimensions.get('screen');

const styles = StyleSheet.create({
  backgroundStyle: {
    position: 'absolute',
    top: 0,
    bottom: 0,
    right: 0,
    left: 0,
    zIndex: 10,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: 'rgba(0, 0, 0, 0.7)',
  },
  modalBox: {
    width: width - 64,
    backgroundColor: Colors.background,
    borderRadius: 8,
  },
});


const CustomModal = (props) => {
  const {
    visible, onRequestClose, children, backgroundStyle,
  } = props;

  return (
    <Modal
      visible={visible}
      onRequestClose={onRequestClose}
      transparent
      animationType="fade"
      presentationStyle="overFullScreen"
    >
      <StatusBar
        translucent
        animated
        backgroundColor="rgba(0, 0, 0, 0.7)"
      />
      <View style={[styles.backgroundStyle, backgroundStyle]}>
        <View style={styles.modalBox}>
          {children}
        </View>
      </View>
    </Modal>
  );
};

CustomModal.propTypes = {
  visible: PropTypes.bool.isRequired,
  onRequestClose: PropTypes.func,
  backgroundStyle: PropTypes.object,
  children: PropTypes.any.isRequired,
};

CustomModal.defaultProps = {
  onRequestClose: () => { },
  backgroundStyle: null,
};

export default CustomModal;
