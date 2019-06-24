import React from 'react';
import { StyleSheet } from 'react-native';
import PropTypes from 'prop-types';
import CustomText from './CustomText';
import Colors from '../common/Colors';


const styles = StyleSheet.create({
  headerText: {
    fontSize: 20,
    color: Colors.onPrimary,
    marginLeft: 16,
    marginRight: 16,
  },
});


const AppBarText = ({ children }) => (
  <CustomText style={styles.headerText}>
    {children}
  </CustomText>
);

AppBarText.propTypes = {
  children: PropTypes.string.isRequired,
};

export default AppBarText;
