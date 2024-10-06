import React, { useEffect } from 'react';
import { useHistory } from '@docusaurus/router';

export default function Home(): JSX.Element {
  const history = useHistory();

  useEffect(() => {
    history.push('/cpp-algorithm-snippets/docs/intro');
  }, [history]);

  return (<></>);
}