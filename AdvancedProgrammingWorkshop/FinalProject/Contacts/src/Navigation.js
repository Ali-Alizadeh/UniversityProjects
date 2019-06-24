import {
  createAppContainer,
  createStackNavigator,
} from 'react-navigation'
import Home from './screens/Home'
import Contact from './screens/Contact'

const MainNav = createStackNavigator(
  {
    Home,
    Contact,
  }, {
    headerMode: 'none'
  }
)

export default createAppContainer(MainNav)
